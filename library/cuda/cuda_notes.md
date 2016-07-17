# Notes for learning CUDA

Here are some notes for learning CUDA using the Udacity's course *Introduction
to Parallel Programming*.

## GPU Hardware Architecture

### Communication Patterns

The term *Communication Patterns* is only used in this course. It describes the
memory access patterns when threads read inputs from memory and write outputs to
memory. The concept is not very formal but it's helpful to understand the
synchronization problem. Following five patterns are introduced in the course:

- Mapping: `outputArr[i] = inputArr[i]`

- Gather: A thread reads data from different locations in the input array, then
write them into one location in the output array.

- Scatter: A thread picks up a piece of data from **ONE** location in the input
array, and then write it into **at least one** locations of the output array. To
be noticed, there could be threads synchronization problem here.

- Stencil: Stencil is a special case of gather. A thread in stencil pattern only
reads from the (logical) neighbors of one location in the input array. For
example, 2-D filters in image processing could be treated as a stencil.

- Transpose: The interesting part of transpose is transposing an array of
structures (AOS) into a structure of arrays (SOA).

### Memory Model of CUDA

There are three levels of memory:

- Local memory: Mostly stored in registers. The variables initialized in kernel
scope are stored in local memory, including those in parameter list. The fastest
memory.

- Shared memory: Mostly stored in caches. It can be allocated when launching a
kernel by specifying the size of shared memory at the third parameter in
`<<< >>>`. To access them in kernel, you need declare
`extern __shared__ type name[]` in kernel. Every thread block has its own shared
memory, i.e. only the threads within the same thread block can access the same
shared memory. Shared memory is the second fastest memory.

- Global memory: Mostly stored in GPU main memory. The are created before kernel
launching by the `cudaMalloc`. Remember to release them (`cudaFree`) after
using. The slowest memory in GPU, but still much faster than the host's main
memory.

## CUDA Performance Optimization
