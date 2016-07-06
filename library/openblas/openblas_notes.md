# Notes for OpenBLAS

## Installation

Environment: RWTH HPC cluster (linuxnvc01), Intel(R) Xeon(R) CPU E2-2650,
CentOS 7.2.1511, gcc/5.3

Because of the version problem of the ICC on the cluster, some of the GCC
instructions cannot be recognized. To solve it, use `make CC=gcc`. After
compiling, related shared library and static library will be generated. Their
names start with `libopenblas`, just using `cp libopenblas* [DEST]` will finish
installing.

## Memory layout and parameters used in `cblas_xgemm`

When we create matrix in memory, the logical form of a matrix is a 2-dimensional
array, which is essentially a 1-dimensional array locating in memory
continuously:

<img src="https://github.com/tongsucn/ts-toolkit/blob/master/library/openblas/img/layout.png" width=512>

So you should have found the problem, which one is correct? Actually it depends
on the language you use. If you use Fortran, it will be in the second case. It
is called *Column Major Order*. If you use C, then the first one is the case,
which is called *Row Major Order*. It is well known that reading from continuous
memory will get benefits from CPU's prefetching instructions. Therefore, if we
tell the library in advance, that how a matrix lays in memory, then the library
could achieve higher performance by adjusting computing orders.

## The parameters used in cblas_xgemm functions

GEMM in BLAS means general matrix-matrix multiplication:

<img src="https://github.com/tongsucn/ts-toolkit/blob/master/library/openblas/img/xgemm_formula.png" width=512>

The op here means transpose. It is specified by the `TransA` and `TransB`
parameters.

### Parameter `Order`

The dimension, in which the elements are continuous in memory (row major order).
E.g. when the elements in a row are continuous in memory, then `CblasRowMajor`
should be set, and vice versa. To be noticed is that, it describes the input
matrix itself, rather than the transposed input matrix, where the transpose is
specified by parameter `TransA` and `TransB`.

It is set by enumeration `CBLAS_ORDER` in CBLAS.

```C
enum CBLAS_ORDER {
    CblasRowMajor = 101,    /// Row major order
    CbalsColMajor = 102     /// Column major order
};
```

### Parameter `TransA` and `TransB`

The transpose flags for matrix A and matrix B. When set, the input matrix will
be firstly transposed, then multiplication will be executed. The transposition
here is the *in-place* transpose.

The type is enumeration `CBLAS_TRANSPOSE` in CBLAS. The third is conjugating
transpose, which works only on complex precisions (`cblas_cgemm` and
`cblas_zgemm`). For non-complex precisions (`cblas_sgemm` and `cblas_dgemm`), it
acts exactly the same with `CblasTrans`.

```C
enum CBLAS_TRANSPOSE {
    CblasNoTrans    = 111,  /// No transpose, op(X) = X
    CblasTrans      = 112,  /// Transpose, op(X) = X^{T}
    CblasConjTrans  = 113   /// Conjugating transpose, op(X) = X^{*}
};
```

### Parameter `M`, `N` and `K`

- `M` is the number of rows in op(A) and matrix C. It must be at least 0.

- `N` is the number of columns in op(B) and matrix C. It must be at least 0.

- `K` is the number of columns in op(A) and rows in op(B). It must be at least
0.

### Parameter `alpha` and `beta`

The scale factor, the must be in the same precision with the matrices.

### Parameter `A`, `B` and `C`

The input matrices. Please remember to cast the pointer's type before passing it
to the function.

### Parameter `lda`, `ldb` and `ldc`

The leading dimension of matrices A, B and C. Leading dimension is related to
the first parameter `Order`. It must have at least the same value as the length
of major order dimension of the related matrix. For example, if we use
`CblasRowMajor`, then `lda` >= `K`. To be noticed is that `lda` could be larger
than the major order length of the matrix we use in computation. This is very
helpful when we perform sub-matrix multiplication. For example:

<img src="https://github.com/tongsucn/ts-toolkit/blob/master/library/openblas/img/lda.png" width=512>

In this row major order case, the elements right after a row is not the elements
in the next row. If we indicate the parent matrix's row size, then the library
can use suitable CPU prefetching instructions to avoid prefetching a lot of
useless data (e.g. in this case, the elements after the first row).

