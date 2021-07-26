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

class Graph
{
public:
    Graph() : m_node(nullptr), m_nodeCount(0) {}
    ~Graph();

    bool addNode(Node* node);
    const Node* getNode();

private:
    Node*         m_node;
    unsigned      m_nodeCount;
    std::mutex    m_mutex;
};
