/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */

#include "graph.h"

Graph::~Graph()
{
    delete m_node;
}

bool Graph::addNode(Node* node)
{
    std::lock_guard<std::mutex> l(m_mutex);
    if (m_nodeCount > 0)
    {
        //Only single-node graphs are supported
        return false;
    }
    m_node = node;
    ++m_nodeCount;
    return true;
}

const Node* Graph::getNode()
{
    std::lock_guard<std::mutex> l(m_mutex);
    return m_node;
}