#include "test_infra.h"
#include "synapse_common_types.h"
#include <string>
#include <iostream>

namespace HabanaTest
{

TestArguments parseArguments(int argc, char* argv[])
{
    TestArguments args;
    for (unsigned idx = 1; idx < argc; idx++)
    {
        std::string argStr(argv[idx]);
        if(argStr.compare("-device") == 0)
        {
            idx++;
            std::string deviceStr(argv[idx]);
            if (deviceStr.compare("gaudi2") == 0)
            {
                args.deviceType = synDeviceGaudi2;
            }
            else if (deviceStr.compare("gaudi") == 0)
            {
                args.deviceType = synDeviceGaudi;
            }
        }
    }
    return args;
}

void random_init_buffer(float *buf, unsigned nElems) {
  srand(2021);
  for (unsigned i = 0; i < nElems; ++i) {
    buf[i] = (float)std::rand();
  }
}
float get_rand_between(float min, float max) {
  float ret = (float)(std::rand() / (float)RAND_MAX); //[0, 1]
  ret = ret * (max - min);                            //[0, Max+min]
  return ret - min;                                   //[min, max];
}

void validate_output(float *output, float *ref) {
  bool error = false;
  const float eps = 1e-6;
  float *pOutput = output;
  float *pRef = ref;
  for (unsigned b = 0; b < 1; ++b) {
    for (unsigned h = 0; h < 3; ++h) {
      for (unsigned w = 0; w < 3; ++w) {
        for (unsigned c = 0; c < 2; ++c) {
          if (std::abs(*pOutput - *pRef) > eps) {
            std::cout << "Error at [" << c << "," << w << "," << h << "," << b
                      << "]: Output:" << *pOutput << " Ref: " << *pRef
                      << std::endl;
            error = true;
          }
          ++pOutput;
          ++pRef;
        }
      }
    }
  }
  if (!error) {
    std::cout << "Comparison passed successfully" << std::endl;
  }
}
} // namespace HabanaTest