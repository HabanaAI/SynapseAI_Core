/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */

#pragma once
#include <vector>
#include <mutex>
#include <memory>
#include "tensor.h"
#include "node.h"

#include "synapse_common_types.h"

class Graph
{
public:
    Graph(synDeviceType deviceType) : m_node(nullptr), m_nodeCount(0), m_deviceType(deviceType) {}
    ~Graph();

    bool addNode(Node* node);
    const Node* getNode();
    synDeviceType getDeviceType() const {return m_deviceType;}

private:
    Node*         m_node;
    unsigned      m_nodeCount;
    std::mutex    m_mutex;
    synDeviceType m_deviceType;
};
