#include <iostream>

/**
 * @brief Perform general 1-D grid, 2-D block reduce, along X-direction.
 *
 * @details This device function implements the reduce algorithms. The grid is
 * in 1-D X-direction, i.e. `gridDim.x >= 1`,`gridDim.y == 1` and
 * `gridDim.z == 1`. The block is in 2-D X- and Y-direction, i.e.
 * `blockDim.x >= 1` and `blockDim.y >= 1`, `blockDim.z == 1`. To achieve higher
 * parallelization, the shared memory will have size
 * `blockDim.x * blockDim.y * 2`. The input array will be *divided* into smaller
 * parts and assigned to each thread block. That is, each block will be assigned
 * an *sub-array* with length at most `blockDim.x * blockDim.y * 2`.
 *
 * @tparam      DataType        The type of data, which is processed.
 * @tparam      Operation       The operation type, it is related to the lambda
 * function parameter.
 *
 * @param[in]   d_inputArr      The input array, type is determined by the
 * template.
 *
 * @param[in]   inputArrLength  The length of the input array.
 * @param[out]  d_outputArr     The output array, in device memory, type is
 * determined by the template. The length of it must be `gridDim.x * blockDim.y`
 *
 * @param[in]   oper            The operation performed on two elements in the
 * array. It should be a function or lambda expression defined in a
 * `__global__` function, which has two reference parameters. The result on
 * these two parameters will be stored in the first parameter, the second
 * parameter should be set to identity.
 *
 * @param[in]   identity        The identity of the operation. (The same concept
 * in group theory.)
 *
 */
template < class DataType, class Operation >
__device__
void
g1b2_reduce_x(
        const DataType *const   d_inputArr,
        const size_t            inputArrLength,
        DataType *const         d_outputArr,
        const Operation         &oper,
        const DataType          identity
        ) {
    // Make shared memory visible in kernel
    extern __shared__ DataType sdata[];

    // Calculate indices
    int sdataAbsIdx = threadIdx.x * blockDim.y + threadIdx.y;
    int initStride = blockDim.x * blockDim.y;
    int inputArrAbsIdx = 2 * blockIdx.x * initStride + sdataAbsIdx;

    // Initialize shared memory according to the absolute location of
    // thread-releated element in the input array. If a thread-related element
    // does not exist, the corresponding shared memory will be filled with
    // identity value of the operation.
    if (inputArrAbsIdx >= inputArrLength) {
        // The thread-related left element does not exist in the input array.
        sdata[sdataAbsIdx] = identity;
        sdata[sdataAbsIdx + initStride] = identity;
    }
    else if (inputArrAbsIdx + initStride >= inputArrLength) {
        // The thread-related right element does not exist in the input array.
        sdata[sdataAbsIdx] = d_inputArr[inputArrAbsIdx];
        sdata[sdataAbsIdx + initStride] = identity;
    }
    else {
        // The thread-related elements exist in the input array.
        sdata[sdataAbsIdx] = d_inputArr[inputArrAbsIdx];
        sdata[sdataAbsIdx + initStride]
            = d_inputArr[inputArrAbsIdx + initStride];
    }
    // Thread synchronization, wait for shared memory initialization's finish.
    __syncthreads();

    // Perform reduce, the initial stride is blockDim.x
    for (unsigned int stride = static_cast<unsigned int>(blockDim.x);
        stride > 0;
        stride = (stride & 0x1) ? stride >> 1 + 1 : stride >> 1) {
        // The thread with X-ID smaller than the stride will be omitted.
        if (threadIdx.x < stride)
            // Compute absolute stride and perform operation
            oper(sdata[sdataAbsIdx], sdata[sdataAbsIdx + stride * blockDim.y]);
        // Thread synchronization after every stride.
        __syncthreads();
    }

    // Because reduce is executed in X-direction, only the elements in shared
    // memory related to the `threadIdx.x == 0` stored the results. Here only
    // the corresponding elements will be written into the output array.
    if (0 == threadIdx.x)
        d_outputArr[blockIdx.x * blockDim.y + threadIdx.y] = sdata[sdataAbsIdx];
}

#define HIST_WIDTH      128
#define HIST_NUM        8
#define BLOCK_NUM       512
#define DATA_LENGTH     (2 * HIST_WIDTH * HIST_NUM * BLOCK_NUM + HIST_WIDTH * 3)
#define RESULT_LENGTH   HIST_WIDTH * (BLOCK_NUM + 1)

__global__
void
add_oper(
        const int *const        d_inputArr,
        const size_t            inputArrLength,
        int *const              d_outputArr
        ) {
    // Identity and lambda of the operation.
    const int identity = 0;
    auto oper = [](int &l, int &r) -> void { l += r; r = 0; };

    // Launch the device function.
    g1b2_reduce_x(d_inputArr, DATA_LENGTH, d_outputArr, oper, identity);
}

int main() {
    // All kinds of sizes.
    // Shared memory's size (in bytes).
    int sharedBytes = 2 * sizeof(int) * HIST_WIDTH * HIST_NUM;

    // Input array's size (in bytes).
    int dataBytes   = sizeof(int) * DATA_LENGTH;

    // Result array's size (in bytes).
    int resultBytes = sizeof(int) * RESULT_LENGTH;

    // Data arrays
    // Input array, host.
    int h_inputArr[DATA_LENGTH];
    // Output array, host.
    int h_outputArr[RESULT_LENGTH];

    // Initialization of input array.
    for (int idx = 0; idx < DATA_LENGTH; ++idx)
        h_inputArr[idx] = idx % HIST_WIDTH;


    // CUDA kernel sizes
    // Grid size
    const dim3 gridSize(BLOCK_NUM);
    // Thread block size
    const dim3 blockSize(HIST_NUM, HIST_WIDTH);

    // Allocating device memory
    int *d_inputArr, *d_outputArr;
    int ret = cudaMalloc(&d_inputArr, dataBytes);
    if (cudaSuccess != ret)
        std::cout << "Cannot allocate d_inputArr, ret: " << ret << std::endl;
    ret = cudaMalloc(&d_outputArr, resultBytes);
    if (cudaSuccess != ret)
        std::cout << "Cannot allocate d_outputArr, ret: " << ret << std::endl;

    // Copy host array to device
    ret = cudaMemcpy(d_inputArr, h_inputArr, dataBytes, cudaMemcpyHostToDevice);
    if (cudaSuccess != ret)
        std::cout << "Cannot memcpy to device, ret: " << ret << std::endl;

    add_oper<<< BLOCK_NUM + 1, blockSize, sharedBytes >>>(
            d_inputArr, DATA_LENGTH, d_outputArr);

    ret = cudaMemcpy(h_outputArr, d_outputArr, resultBytes,
            cudaMemcpyDeviceToHost);
    if (cudaSuccess != ret)
        std::cout << "Cannot memcpy to host, ret: " << ret << std::endl;

    for (int idx = RESULT_LENGTH - 512; idx < RESULT_LENGTH; ++idx)
        std::cout << h_outputArr[idx] << " ";
    std::cout << std::endl;

    cudaFree(d_inputArr);
    cudaFree(d_outputArr);

    return 0;
}
