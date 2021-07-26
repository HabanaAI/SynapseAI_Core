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
#include "node.h"
#include "kernel_db.h"
#include "index_space.h"

class Recipe
{
public:
    Recipe();
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
    void SetKernelParams();

    void SetTensor(gcapi::Tensor_t* gTensor, Tensor* tensor);

    void AllocateAuxBuffer();
    void AllocateELFBuffer();

    void PartitionIndexSpace();

    typedef std::pair<void*, unsigned> AuxTensorData;

private:
    std::vector<Tensor*> m_tensors;
    std::string          m_guid;
    char*                m_params;
    unsigned             m_paramSize;
    unsigned             m_numInputs;
    unsigned             m_numAuxTensors;
    unsigned             m_firstAux;
    char*                m_auxBuffer;
    char*                m_elfBuffer;

    std::vector<AuxTensorData>         m_auxTensorData;
    std::vector<IndexSpace>            m_indexSpacePartition;

    gcapi::HabanaKernelParams_t        m_kernelParams;
    gcapi::HabanaKernelInstantiation_t m_kernelInstance;
};
