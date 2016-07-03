Debuging the TTC/TCC C API

## Bugs I met

1. When generating transpose shared library with g++ or icpc, both compiling and
linking need provide `-fopenmp` flag.

2. When generating C++ code, *DO NOT* use `int32_t` to replace `int`, it could
cause troubles. Type casting, e.g. from `void *` to `float *` must be provided
explicitly. Otherwise segmentation fault would be raised.

3. When using CUDA, the parameters `lda` and `ldb` must be provided.

4. When generating code, using MACRO to deal with code variation.

