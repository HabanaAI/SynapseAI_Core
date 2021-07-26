/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */

#include <cstring>
#include <list>
#include "recipe.h"
#include "tpc_elf_api.hpp"

Recipe::Recipe() : m_params(nullptr), m_paramSize(0), m_numInputs(0), m_numAuxTensors(0), m_firstAux(0), m_auxBuffer(nullptr), m_elfBuffer(nullptr)
{
    memset(&m_kernelParams, 0, sizeof(m_kernelParams));
    memset(&m_kernelInstance, 0, sizeof(m_kernelInstance));
}

Recipe::~Recipe()
{
    for (Tensor* t : m_tensors)
    {
        delete t;
    }
    delete[] m_params;
    delete[] m_auxBuffer;
    delete[] m_elfBuffer;
}

void Recipe::Compile(Graph *g, KernelDB* db)
{
    const Node* node = g->getNode();
    m_numInputs = node->GetInputs().size();
    for (Tensor* t : node->GetInputs())
    {
        m_tensors.push_back(t->Clone());
    }
    for (Tensor* t : node->GetOutputs())
    {
        m_tensors.push_back(t->Clone());
    }
    m_paramSize = node->GetParamSize();
    if (m_paramSize > 0)
    {
        m_params = new char[m_paramSize];
        memcpy(m_params, node->GetParams(), m_paramSize);
    }
    m_guid = node->GetGUID();

    SetKernelParams();
    gcapi::GlueCodeReturn_t ret = db->GetKernelInstantiation(&m_kernelParams, &m_kernelInstance);
    while (ret != gcapi::GLUE_SUCCESS)
    {
        if (ret == gcapi::GLUE_INSUFICIENT_AUX_BUFFER_SIZE)
        {
            //Special case, need to allocate auxiliary buffers
            AllocateAuxBuffer();
        }
        else if (ret == gcapi::GLUE_INSUFICIENT_ELF_BUFFER)
        {
            AllocateELFBuffer();
        }
        else
        {
            break;
        }
        ret = db->GetKernelInstantiation(&m_kernelParams, &m_kernelInstance);
    }
    if (ret != gcapi::GLUE_SUCCESS) return;

    //Copy from ELF to instance
    TpcElfTools::ExtractTpcBinaryFromElf(m_kernelInstance.kernelElf, m_kernelInstance.elfSize, m_kernelInstance.kernel.kernelBinary, m_kernelInstance.kernel.binarySize);
    TpcElfTools::TPCProgramHeader header;
    TpcElfTools::ExtractTpcProgramHeaderFromElf(m_kernelInstance.kernelElf, m_kernelInstance.elfSize, header);
    m_kernelInstance.flags.specialFunctionsUsed = header.specialFunctionUsed;

    PartitionIndexSpace();
}

unsigned Recipe::GetNumTensors()
{
    return m_tensors.size();
}

unsigned Recipe::GetNumAux()
{
    return m_numAuxTensors;
}

const Tensor* Recipe::GetTensor(unsigned int idx)
{
    if (idx >= m_tensors.size()) return nullptr;
    return m_tensors[idx];
}

float Recipe::GetPaddingValue(unsigned int idx)
{
    if (idx < m_numInputs)
    {
        return m_kernelInstance.inputPadValues[idx].fValue;
    }
    return 0.f;
}

void Recipe::PartitionIndexSpace()
{
    m_indexSpacePartition.clear();
    std::list<IndexSpace> curPartition;

    //Seed partitions
    IndexSpace idxSpace;
    for (unsigned i = 0; i < 5; ++i)
    {
        idxSpace.size[i]   = m_kernelInstance.indexSpaceGeometry.sizes[i];
        idxSpace.offset[i] = 0;
        if (idxSpace.size[i] == 0) idxSpace.size[i] = 1;
    }

    const unsigned nPartitions = 8;
    curPartition.push_back(idxSpace);
    while (curPartition.size() < nPartitions)
    {
        IndexSpace cur = curPartition.front();
        //look for a dimension to split
        int dim;
        for (dim = 4; dim >=0; --dim)
        {
            if ((cur.size[dim] > 0) && (cur.size[dim] % 2 == 0))
            {
                break;
            }
        }
        if (dim < 0) break; //Can't partition further
        //partition "dim"
        curPartition.pop_front();
        cur.size[dim] /= 2;
        curPartition.push_back(cur);
        cur.offset[dim] += cur.size[dim];
        curPartition.push_back(cur);
    }

    m_indexSpacePartition.insert(m_indexSpacePartition.end(), curPartition.begin(), curPartition.end());
}

void Recipe::SetKernelParams()
{
    m_kernelParams.NodeParams      = m_params;
    m_kernelParams.NodeParamsSize  = m_paramSize;
    m_kernelParams.kernelType      = gcapi::KERNEL_TYPE_INFERENCE;
    m_kernelParams.deviceId        = gcapi::DEVICE_ID_GAUDI;
    m_kernelParams.apiVersion      = 1;
    m_kernelParams.inputTensorNr   = m_numInputs;
    m_kernelParams.outputTensorNr  = m_tensors.size() - m_numInputs;
    m_kernelParams.debugFlags      = 0;
    m_kernelParams.maxAvailableTpc = 8;
    memcpy(m_kernelParams.nodeName, m_guid.c_str(), std::min(m_guid.size(), (size_t)gcapi::MAX_NODE_NAME));

    for (unsigned i = 0; i < m_numInputs; ++i)
    {
        SetTensor(m_kernelParams.inputTensors + i, m_tensors[i]);
    }
    for (unsigned i = 0; i < m_tensors.size() - m_numInputs; ++i)
    {
        SetTensor(m_kernelParams.outputTensors + i, m_tensors[i + m_numInputs]);
    }
}

void Recipe::SetTensor(gcapi::Tensor_t *gTensor, Tensor *tensor)
{
    gTensor->dataType   = gcapi::DATA_F32;
    gTensor->Contiguous = true;
    gTensor->Sram       = false;
    gTensor->pData      = nullptr;

    gTensor->geometry.dims = 4;

    for (unsigned i = 0; i < gcapi::MAX_TENSOR_DIM; ++i)
    {
        gTensor->geometry.sizes[i]       = tensor->GetSize(i);
        gTensor->geometry.permutation[i] = i;
    }
}

void Recipe::AllocateAuxBuffer()
{
    unsigned auxSize = 0;
    for (unsigned i = 0; i < m_kernelInstance.auxiliaryTensorCount; ++i)
    {
        auxSize += m_kernelInstance.auxiliaryTensors[i].bufferSize;
    }
    m_auxBuffer     = new char[auxSize * sizeof(float)];
    m_firstAux      = m_tensors.size();
    m_numAuxTensors = m_kernelInstance.auxiliaryTensorCount;
    std::vector<Tensor*> auxTensors;
    auxSize = 0;
    for (unsigned i = 0; i < m_kernelInstance.auxiliaryTensorCount; ++i)
    {
        unsigned tmpSize                           = m_kernelInstance.auxiliaryTensors[i].bufferSize * sizeof(float);
        m_kernelInstance.auxiliaryTensors[i].pData = m_auxBuffer + auxSize;
        m_auxTensorData.push_back(AuxTensorData(m_kernelInstance.auxiliaryTensors[i].pData, tmpSize));
        auxSize += tmpSize;
        std::string tensorName("aux_");
        tensorName += std::to_string(i);
        Tensor* t = new Tensor(tensorName.c_str());
        t->Init(m_kernelInstance.auxiliaryTensors[i].geometry.sizes);
        auxTensors.push_back(t);
    }
    m_tensors.insert(m_tensors.end(), auxTensors.begin(), auxTensors.end());
}

void Recipe::AllocateELFBuffer()
{
    if (m_elfBuffer != nullptr)
    {
        delete[] m_elfBuffer;
        m_elfBuffer = nullptr;
    }
    if (m_kernelInstance.elfSize == 0) return;

    m_elfBuffer                = new char[m_kernelInstance.elfSize];
    m_kernelInstance.kernelElf = m_elfBuffer;
}

bool Recipe::IsTensorAux(unsigned int idx)
{
    return (idx >= m_firstAux) && (idx < m_firstAux + m_numAuxTensors);
}

unsigned Recipe::GetAuxSize(unsigned int idx)
{
    if (!IsTensorAux(idx)) return 0;
    return m_auxTensorData[idx - m_firstAux].second;
}

void* Recipe::GetAuxHostPtr(unsigned int idx)
{
    if (!IsTensorAux(idx)) return 0;
    return m_auxTensorData[idx - m_firstAux].first;
}