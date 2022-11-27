#pragma once
#include "synapse_common_types.h"
#include <synapse_api.h>
#include <cstdlib>

namespace HabanaTest
{

struct TestArguments
{
    synDeviceType deviceType = synDeviceGaudi;
};

TestArguments parseArguments(int argc, char* argv[]);

void random_init_buffer(float *buf, unsigned nElems);

float get_rand_between(float min, float max);

void init_input_and_ref(float *a, float *b, float *ref, unsigned size);

void validate_output(float *output, float *ref);

} // namespace HabanaTest