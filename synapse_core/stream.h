/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */

#pragma once

#include <mutex>
#include <atomic>
#include <synapse_api.h>

class Stream
{
public:
    Stream() : m_type(STREAM_TYPE_MAX) {}
    ~Stream() {}

    bool Init(synStreamType type);
    unsigned GetID() { return m_id; }
    synStreamType GetType() { return m_type; }

    static std::atomic<unsigned> g_streamId;

private:
    synStreamType m_type;
    unsigned      m_id;
};
