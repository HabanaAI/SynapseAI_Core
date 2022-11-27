/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */

#pragma once

#include <vector>
#include <gc_interface.h>
#include "graph.h"
#include "hw_abstraction_layer.h"
#include "node.h"
#include "kernel_db.h"
#include "index_space.h"

gcapi::DeviceId_t deviceIdfromDeviceType(synDeviceType deviceType);

class Recipe
{
public:
    Recipe(const synDeviceType deviceType);
    ~Recipe();

    void Compile(Graph* g, KernelDB* db);
    unsigned GetNumTensors();
    const Tensor* GetTensor(unsigned idx);
    float GetPaddingValue(unsigned idx);

    const gcapi::HabanaKernelParams_t* GetParams()          { return &m_kernelParams; }
    const gcapi::HabanaKernelInstantiation_t* GetInstance() { return &m_kernelInstance; }

    std::vector<IndexSpace> GetIndexSpacePartition()        { return m_indexSpacePartition; }

    //Auxiliary tensor handling
    bool     IsTensorAux(unsigned idx);
    unsigned GetNumAux();
    unsigned GetAuxSize(unsigned idx);
    void*    GetAuxHostPtr(unsigned idx);

protected:
    void SetKernelParams(synDeviceType deviceType);

    void SetTensor(gcapi::Tensor_t* gTensor, Tensor* tensor);

    void AllocateAuxBuffer();
    void AllocateELFBuffer();

    void PartitionIndexSpace();
    std::shared_ptr<HWAbstractionLayer> GetHal() {return m_hal;}
    typedef std::pair<void*, unsigned> AuxTensorData;

private:
    std::vector<Tensor*> m_tensors;
    std::string          m_guid;
    char*                m_params = nullptr;
    unsigned             m_paramSize = 0;
    unsigned             m_numInputs = 0;
    unsigned             m_numAuxTensors = 0;
    unsigned             m_firstAux = 0;
    char*                m_auxBuffer = nullptr;
    char*                m_elfBuffer = nullptr;

    std::vector<AuxTensorData>          m_auxTensorData;
    std::vector<IndexSpace>             m_indexSpacePartition;
 
    gcapi::HabanaKernelParams_t         m_kernelParams = {0};
    gcapi::HabanaKernelInstantiation_t  m_kernelInstance = {{0}};
    std::shared_ptr<HWAbstractionLayer> m_hal = nullptr;
};
