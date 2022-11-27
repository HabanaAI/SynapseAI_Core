/* SPDX-License-Identifier: MIT
 *
 * Copyright 2016-2021 HabanaLabs, Ltd.
 * All Rights Reserved.
 *
 */

#pragma once

#include <cstdint>
#include <vector>

namespace tpc_gaudi {
    void buildSpecialFunctionCoefficients(std::vector<std::vector<uint8_t>> &specialFunctionCoefficients);
	uint8_t *getLUTStartAddressFromFuncID(uint32_t funcID, uint8_t* baseAddr);
	uint32_t getCoefAddrFromOffset(uint8_t offset, bool isLOOKUP, uint32_t elementSize);
}

namespace tpc_gaudi2
{
void     buildSpecialFunctionCoefficients(std::vector<std::vector<uint8_t>>& specialFunctionCoefficients);
uint8_t* getLUTStartAddressFromFuncID(uint32_t funcID, uint8_t* baseAddr);
uint32_t getCoefAddrFromOffset(uint8_t offset, bool isLOOKUP, uint32_t elementSize);
} // namespace tpc_gaudi2
