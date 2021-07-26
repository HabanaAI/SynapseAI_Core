/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */

#include "stream.h"

std::atomic<unsigned> Stream::g_streamId(0);

bool Stream::Init(synStreamType type)
{
    m_type = type;
    m_id   = g_streamId++;
    return true;
}