# PROJECT NOT UNDER ACTIVE MANAGEMENT #  
This project will no longer be maintained by Intel.  
Intel has ceased development and contributions including, but not limited to, maintenance, bug fixes, new releases, or updates, to this project.  
Intel no longer accepts patches to this project.  
 If you have an ongoing need to use this project, are interested in independently developing it, or would like to maintain patches for the open source software community, please create your own fork of this project.  
  
# SynapseAI Core
SynapseAI Core is a reference implementation of the SynapseAI API running on Habana Gaudi.

- [SynapseAI Core](#synapseai-core)
  - [Library components](#library-components)
  - [Pre-requisites](#pre-requisites)
  - [Building SynapseAI Core](#building-synapseai-core)
  - [Tests](#tests)
    - [Running the Tensor Division test](#running-the-tensor-division-test)
  - [Limitations](#limitations)

## Library components

SynapseAI Core contains the following elements:

- Synapse Core: an implementation of the SynapseAI APIs. Some APIs are not implemented for brevity, see documentation below.
- Synapse Backend: a library for executing code on Habana Gaudi, using the habanalabs driver and the hl-thunk user-space library.
- TPC Kernels DB: a library containing some sample TPC (Tensor Processing Core) kernels and accompanying host-side code.
- ELFTools: a utility library for parsing ELF sections and extracting metadata generated by the TPC LLVM compiler.
- Tests: Some simple tests to demonstrate how to execute workloads on the device that utilize the TPC engines.

## Pre-requisites

1. Linux kernel with latest habanalabs driver. 
   Gaudi device support was added in kernel 5.7 but to work with a secured device, kernel 5.15 and above is required.

2. hl-thunk library (https://github.com/HabanaAI/hl-thunk)

3. TPC LLVM compiler (https://github.com/HabanaAI/tpc_llvm)

4. cmake version 3.5.1 or higher

5. GCC 7.5 or higher

## Building SynapseAI Core

1. Build the hl-thunk library and TPC LLVM compiler according to their respective instructions.
   From here on, we assume the root of TPC LLVM is $HOME/tpc-llvm and the root of hl-thunk
   is $HOME/hl-thunk
   
2. Clone the repository. From here on, we assume it was cloned to $HOME/SynapseAI_core

3. Run the build.sh script:

```sh
cd $HOME/SynapseAI_Core
EXTRA_CMAKE_FLAGS="-DTPC_LLVM_BIN_PATH=$HOME/tpc-llvm/build/bin -DHLTHUNK_INCLUDE_PATH=$HOME/hl-thunk/include/uapi -DHLTHUNK_LIB_PATH=$HOME/hl-thunk/build/lib" ./build.sh
```

## Tests

There are a couple of tests in the tests folder but currently only two will compile.
In the near future we will add the missing kernels for the rest of the tests.

The tests that can currently be run are:

1. div_test - This test computes division of two tensors on the device. It copies the output to the host and compares the result to a reference implementation on the host.
   The test serves as a demonstration of how to create a graph containing a single node. The node represents a divide operator. The division is implemented using a TPC kernel that performs the computation on the TPC engines.

2. memcpy_test - This test demonstrates how to use the DMA engine to copy a tensor in and out of the device. It doesn't use the TPC engine and doesn't require any TPC kernel.

### Running the Tensor Division test

```sh
cd $HOME/SynapseAI_Core
./build/bin/div_test
```

The expected result should be:
```sh
Comparison passed successfully
```

## Limitations

Limitations of this implementation compared to the closed-source SynapseAI release:

- Operations are synchronous and synchronization occurs through the host.
  - So many APIs, like synStreamWaitEvent, synEventCreate etc, are no-ops.
- This version of the library doesn't implement any operations itself. This means for an operation like reshape or split, the user has to resolve it themselves, or write a TPC kernel to perform it.
- The implementation is limited to single-node graphs. Calling synNodeCreate on a graph that already contains a node will fail.
  - As a corollary, the user must perform all memory management of the Gaudi Memory (HBM)
  - And control edges are not supported since they're not needed
- The "section" mechanism is not supported. All tensors must be created with a null for section handle.
- The user is limited to a single stream per type. Only compute, copy device to host and copy host to device are supported.
- Tensors must be dense in device memory. Strided tensors are not supported.
- Only floating point tensors are supported.
- No profiler support.
- No support for printf from kernels.
- No support for quantization-related APIs, such as providing tensors with static data.
- No support for advanced SynapseAI features, like dynamic shape support or tensors of any rank.

- Unsupported SynapseAI APIs:
  - synRecipeSerialize / Deserialize
  - synDeviceAcquireByModuleID
  - synConfigurationGet/Set
  - synProfilerStart/Stop/GetTrace
  - synConstTensorCreate
  - synEventElapsedTime always returns 0
