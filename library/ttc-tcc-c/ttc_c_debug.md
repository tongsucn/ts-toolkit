Debuging the TTC/TCC C API

## Bugs I met

1. When generating transpose shared library with g++ or icpc, both compiling and
linking need provide `-fopenmp` flag.

2. When generating C++ code, *DO NOT* use `int32_t` to replace `int`, it could
cause troubles. Type casting, e.g. from `void *` to `float *` must be provided
explicitly. Otherwise segmentation fault would be raised.

3. When using CUDA, the parameters `lda` and `ldb` must be provided.

4. When generating code, using MACRO to deal with code variation.

5. The TTC generated CUDA code is sometimes buggy. When data type is `zc`, the
generated file's name starts with `zs` rather than `zc`. But the interface
function's name still starts with `zc`.

6. The CUDA interface function does not take responsibility of allocating device
memory for input and output tensor. Therefore I must write a new file allocating
them and transfer the memory content between host and device.

7. Another bug happens when initializing the function pointer in `ttc_plan_s`.
function pointer for CUDA is different with the one for general. After locating
the symbol, if the pointer is not assigned correctly (e.g. assign CUDA function
interface to general function pointer), segmentation fault will happen.
