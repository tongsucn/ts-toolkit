#ifndef CBLAS_H
#define CBLAS_H
#include <stddef.h>

/*
 * Enumerated and derived types
 */
#define CBLAS_INDEX size_t  /* this may vary between platforms */

enum CBLAS_ORDER {CblasRowMajor=101, CblasColMajor=102};
enum CBLAS_TRANSPOSE {CblasNoTrans=111, CblasTrans=112, CblasConjTrans=113};
enum CBLAS_UPLO {CblasUpper=121, CblasLower=122};
enum CBLAS_DIAG {CblasNonUnit=131, CblasUnit=132};
enum CBLAS_SIDE {CblasLeft=141, CblasRight=142};

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ===========================================================================
 * Prototypes for level 1 BLAS functions (complex are recast as routines)
 * ===========================================================================
 */

/**
 * @brief Dot product of two vectors with single precision.
 *
 * @details $result = \alpha + X \cdot Y$
 *
 * @param[in] N     Size of vector.
 * @param[in] alpha See the above formula.
 * @param[in] X     Input vector 1, single precision.
 * @param[in] incX  Stride within input vector 1 when computing.
 * @param[in] Y     Input vector 2, single precision.
 * @param[in] incY  Stride within input vector 2 when computing.
 *
 * @return Single precision result.
 *
 */
float
cblas_sdsdot(
        const int   N,
        const float alpha,
        const float *X,
        const int   incX,
        const float *Y,
        const int   incY
        );


/**
 * @brief Dot product of two vectors with single precision.
 *
 * @details $result = X \cdot Y$
 *
 * @param[in] N     Size of vector.
 * @param[in] X     Input vector 1, single precision.
 * @param[in] incX  Stride within input vector 1 when computing.
 * @param[in] Y     Input vector 2, single precision.
 * @param[in] incY  Stride within input vector 2 when computing.
 *
 * @return Double precision result.
 *
 */
double
cblas_dsdot(
        const int   N,
        const float *X,
        const int   incX,
        const float *Y,
        const int   incY
        );


/**
 * @brief Dot product of two vectors with single precision.
 *
 * @details $result = X \cdot Y$
 *
 * @param[in] N     Size of vector.
 * @param[in] X     Input vector 1, single precision.
 * @param[in] incX  Stride within input vector 1 when computing.
 * @param[in] Y     Input vector 2, single precision.
 * @param[in] incY  Stride within input vector 2 when computing.
 *
 * @return Single precision result.
 *
 */
float
cblas_sdot(
        const int   N,
        const float *X,
        const int   incX,
        const float *Y,
        const int   incY
        );


/**
 * @brief Dot product of two vectors with double precision.
 *
 * @details $result = X \cdot Y$
 *
 * @param[in] N     Size of vector.
 * @param[in] X     Input vector 1, double precision.
 * @param[in] incX  Stride within input vector 1 when computing.
 * @param[in] Y     Input vector 2, double precision.
 * @param[in] incY  Stride within input vector 2 when computing.
 *
 * @return Double precision result.
 *
 */
double
cblas_ddot(
        const int       N,
        const double    *X,
        const int       incX,
        const double    *Y,
        const int       incY
        );

/*
 * Functions having prefixes Z and C only
 */

/**
 * @brief Dot product of two vectors with single complex precision.
 *
 * @details $result = X \cdot Y$
 *
 * @param[in]   N       Size of vector.
 * @param[in]   X       Input vector 1, single complex precision.
 * @param[in]   incX    Stride within input vector 1 when computing.
 * @param[in]   Y       Input vector 2, single complex precision.
 * @param[in]   incY    Stride within input vector 2 when computing.
 * @param[out]  dotu    Result with single complex precision
 *
 */
void
cblas_cdotu_sub(
        const int   N,
        const void  *X,
        const int   incX,
        const void  *Y,
        const int   incY,
        void        *dotu
        );


/**
 * @brief Dot product of two vectors with single complex precision, conjugating
 * first vector.
 *
 * @details $result = \bar{X} \cdot Y$
 *
 * @param[in]   N       Size of vector.
 * @param[in]   X       Input vector 1, single complex precision.
 * @param[in]   incX    Stride within input vector 1 when computing.
 * @param[in]   Y       Input vector 2, single complex precision.
 * @param[in]   incY    Stride within input vector 2 when computing.
 * @param[out]  dotu    Result with single complex precision
 *
 */
void
cblas_cdotc_sub(
        const int   N,
        const void  *X,
        const int   incX,
        const void  *Y,
        const int   incY,
        void        *dotc
        );


/**
 * @brief Dot product of two vectors with double complex precision.
 *
 * @details $result = X \cdot Y$
 *
 * @param[in]   N       Size of vector.
 * @param[in]   X       Input vector 1, double complex precision.
 * @param[in]   incX    Stride within input vector 1 when computing.
 * @param[in]   Y       Input vector 2, double complex precision.
 * @param[in]   incY    Stride within input vector 2 when computing.
 * @param[out]  dotu    Result with double complex precision
 *
 */
void
cblas_zdotu_sub(
        const int   N,
        const void  *X,
        const int   incX,
        const void  *Y,
        const int   incY,
        void        *dotu
        );


/**
 * @brief Dot product of two vectors with double complex precision, conjugating
 * first vector.
 *
 * @details $result = \bar{X} \cdot Y$
 *
 * @param[in]   N       Size of vector.
 * @param[in]   X       Input vector 1, double complex precision.
 * @param[in]   incX    Stride within input vector 1 when computing.
 * @param[in]   Y       Input vector 2, double complex precision.
 * @param[in]   incY    Stride within input vector 2 when computing.
 * @param[out]  dotu    Result with double complex precision
 *
 */
void
cblas_zdotc_sub(
        const int   N,
        const void  *X,
        const int   incX,
        const void  *Y,
        const int   incY,
        void        *dotc
        );


/*
 * Functions having prefixes S D SC DZ
 */

/**
 * @brief Euclidean norm of vector with single precision.
 *
 * @details $result = \sqrt{\sum_{i = 1}^{D}{x_{i}^{2}}}$
 *
 * @param[in] N     Size of vector.
 * @param[in] X     Input vector, single precision.
 * @param[in] incX  Stride within input vector when computing.
 *
 * @return Double precision result.
 *
 */
float
cblas_snrm2(
        const int   N,
        const float *X,
        const int   incX
        );


/**
 * @brief Sum of the absolute value of elements in vector with single precision.
 *
 * @details $result = \sum_{i}^{D}{|x_{i}|}$
 *
 * @param[in] N     Size of vector.
 * @param[in] X     Input vector, single precision.
 * @param[in] incX  Stride within input vector when computing.
 *
 * @return Single precision result.
 *
 */
float
cblas_sasum(
        const int   N,
        const float *X,
        const int   incX
        );


/**
 * @brief Euclidean norm of vector with double precision.
 *
 * @details $result = \sqrt{\sum_{i = 1}^{D}{x_{i}^{2}}}$
 *
 * @param[in] N     Size of vector.
 * @param[in] X     Input vector, double precision.
 * @param[in] incX  Stride within input vector when computing.
 *
 * @return Double precision result.
 *
 */
double
cblas_dnrm2(
        const int       N,
        const double    *X,
        const int       incX
        );


/**
 * @brief Sum of the absolute value of elements in vector with double precision.
 *
 * @details $result = \sum_{i}^{D}{|x_{i}|}$
 *
 * @param[in] N     Size of vector.
 * @param[in] X     Input vector, double precision.
 * @param[in] incX  Stride within input vector when computing.
 *
 * @return Double precision result.
 *
 */
double
cblas_dasum(
        const int       N,
        const double    *X,
        const int       incX
        );


/**
 * @brief Euclidean norm of vector with single complex precision.
 *
 * @details $result = \sqrt{\sum_{n = 1}^{D}{(x_{n}^{2} + y_{n}^{2})}}$,
 * where $x$ is the real part of a complex number, $y$ is the imaginary part.
 *
 * @param[in] N     Size of vector.
 * @param[in] X     Input vector, single complex precision.
 * @param[in] incX  Stride within input vector when computing.
 *
 * @return Single precision result.
 *
 */
float
cblas_scnrm2(
        const int   N,
        const void  *X,
        const int   incX
        );


/**
 * @brief Sum of the absolute value of elements in vector with single precision.
 *
 * @details $result = \sum_{n}^{D}{|x_{n}| + |y_{n}|}$, where $x$ is the real
 * part of a complex number, $y$ is the imaginary part.
 *
 * @param[in] N     Size of vector.
 * @param[in] X     Input vector, single complex precision.
 * @param[in] incX  Stride within input vector when computing.
 *
 * @return Single precision result.
 *
 */
float
cblas_scasum(
        const int   N,
        const void  *X,
        const int   incX
        );


/**
 * @brief Euclidean norm of vector with double complex precision.
 *
 * @details $result = \sqrt{\sum_{n = 1}^{D}{(x_{n}^{2} + y_{n}^{2})}}$,
 * where $x$ is the real part of a complex number, $y$ is the imaginary part.
 *
 * @param[in] N     Size of vector.
 * @param[in] X     Input vector, double complex precision.
 * @param[in] incX  Stride within input vector when computing.
 *
 * @return Double precision result.
 *
 */
double
cblas_dznrm2(
        const int   N,
        const void  *X,
        const int   incX
        );


/**
 * @brief Sum of the absolute value of elements in vector with double precision.
 *
 * @details $result = \sum_{n}^{D}{|x_{n}| + |y_{n}|}$, where $x$ is the real
 * part of a complex number, $y$ is the imaginary part.
 *
 * @param[in] N     Size of vector.
 * @param[in] X     Input vector, double complex precision.
 * @param[in] incX  Stride within input vector when computing.
 *
 * @return Double precision result.
 *
 */
double
cblas_dzasum(
        const int   N,
        const void  *X,
        const int   incX
        );


/*
 * Functions having standard 4 prefixes (S D C Z)
 */

/**
 * @brief Get index of element with maximum absolute value in a vector with
 * single precision.
 *
 * @details $result = \arg\max_{i}{|x_{i}|}$
 *
 * @param[in] N     Size of vector.
 * @param[in] X     Input vector, single precision.
 * @param[in] incX  Stride within input vector when computing.
 *
 * @return Index.
 *
 */
CBLAS_INDEX
cblas_isamax(
        const int   N,
        const float *X,
        const int   incX
        );


/**
 * @brief Get index of element with maximum absolute value in a vector with
 * double precision.
 *
 * @details $result = \arg\max_{i}{|x_{i}|}$
 *
 * @param[in] N     Size of vector.
 * @param[in] X     Input vector, double precision.
 * @param[in] incX  Stride within input vector when computing.
 *
 * @return Index.
 *
 */
CBLAS_INDEX
cblas_idamax(
        const int       N,
        const double    *X,
        const int       incX
        );


/**
 * @brief Get index of element with maximum absolute value in a vector with
 * single complex precision.
 *
 * @details $result = \arg\max_{n}{|x_{n}| + |y_{n}|}$, where $x_{n}$ is the
 * $n$-th real part of vector $X$ and $y$ is the imaginary part.
 *
 * @param[in] N     Size of vector.
 * @param[in] X     Input vector, single complex precision.
 * @param[in] incX  Stride within input vector when computing.
 *
 * @return Index.
 *
 */
CBLAS_INDEX
cblas_icamax(
        const int   N,
        const void  *X,
        const int   incX
        );


/**
 * @brief Get index of element with maximum absolute value in a vector with
 * double complex precision.
 *
 * @details $result = \arg\max_{n}{|x_{n}| + |y_{n}|}$, where $x_{n}$ is the
 * $n$-th real part of vector $X$ and $y$ is the imaginary part.
 *
 * @param[in] N     Size of vector.
 * @param[in] X     Input vector, double complex precision.
 * @param[in] incX  Stride within input vector when computing.
 *
 * @return Index.
 *
 */
CBLAS_INDEX
cblas_izamax(
        const int   N,
        const void  *X,
        const int   incX
        );



/*
 * ===========================================================================
 * Prototypes for level 1 BLAS routines
 * ===========================================================================
 */

/*
 * Routines with standard 4 prefixes (s, d, c, z)
 */


/**
 * @brief Swap two vectors with single precision.
 *
 * @param[in]       N     Size of vector.
 * @param[in,out]   X     Input vector 1, single precision.
 * @param[in]       incX  Stride within input vector 1 when computing.
 * @param[in,out]   Y     Input vector 2, single precision.
 * @param[in]       incY  Stride within input vector 2 when computing.
 *
 */
void
cblas_sswap(
        const int   N,
        float       *X,
        const int   incX,
        float       *Y,
        const int   incY
        );


/**
 * @brief Copy the content of a vector with single precision to another.
 *
 * @param[in]   N     Size of vector.
 * @param[in]   X     Input vector, single precision.
 * @param[in]   incX  Stride within input vector when computing.
 * @param[out]  Y     Output vector, single precision.
 * @param[in]   incY  Stride within output vector when computing.
 *
 */
void
cblas_scopy(
        const int   N,
        const float *X,
        const int   incX,
        float       *Y,
        const int   incY
        );


/**
 * @brief Constant times a vector plus a vector, with single precision.
 *
 * @details $result = \alpha \cdot X + Y$
 *
 * @param[in]       N       Size of vector.
 * @param[in]       alpha   Alpha to be added, single precision.
 * @param[in]       X       Input vector, single precision.
 * @param[in]       incX    Stride within input vector when computing.
 * @param[in,out]   Y       Output vector, single precision.
 * @param[in]       incY    Stride within output vector when computing.
 *
 */
void
cblas_saxpy(
        const int   N,
        const float alpha,
        const float *X,
        const int   incX,
        float       *Y,
        const int   incY
        );


/**
 * @brief Swap two vectors with double precision.
 *
 * @param[in]       N     Size of vector.
 * @param[in,out]   X     Input vector 1, double precision.
 * @param[in]       incX  Stride within input vector 1 when computing.
 * @param[in,out]   Y     Input vector 2, double precision.
 * @param[in]       incY  Stride within input vector 2 when computing.
 *
 */
void
cblas_dswap(
        const int   N,
        double      *X,
        const int   incX,
        double      *Y,
        const int   incY
        );


/**
 * @brief Copy the content of a vector with double precision to another.
 *
 * @param[in]   N     Size of vector.
 * @param[in]   X     Input vector, double precision.
 * @param[in]   incX  Stride within input vector when computing.
 * @param[out]  Y     Output vector, double precision.
 * @param[in]   incY  Stride within output vector when computing.
 *
 */
void
cblas_dcopy(
        const int       N,
        const double    *X,
        const int       incX,
        double          *Y,
        const int       incY
        );


/**
 * @brief Constant times a vector plus a vector, with double precision.
 *
 * @details $result = \alpha \cdot X + Y$
 *
 * @param[in]       N       Size of vector.
 * @param[in]       alpha   Alpha to be added, double precision.
 * @param[in]       X       Input vector, double precision.
 * @param[in]       incX    Stride within input vector when computing.
 * @param[in,out]   Y       Output vector, double precision.
 * @param[in]       incY    Stride within output vector when computing.
 *
 */
void
cblas_daxpy(
        const int       N,
        const double    alpha,
        const double    *X,
        const int       incX,
        double          *Y,
        const int       incY
        );


/**
 * @brief Swap two vectors with single complex precision.
 *
 * @param[in]       N     Size of vector.
 * @param[in,out]   X     Input vector 1, single complex precision.
 * @param[in]       incX  Stride within input vector 1 when computing.
 * @param[in,out]   Y     Input vector 2, single complex precision.
 * @param[in]       incY  Stride within input vector 2 when computing.
 *
 */
void
cblas_cswap(
        const int   N,
        void        *X,
        const int   incX,
        void        *Y,
        const int   incY
        );


/**
 * @brief Copy the content of a vector with single complex precision to another.
 *
 * @param[in]   N     Size of vector.
 * @param[in]   X     Input vector, single complex precision.
 * @param[in]   incX  Stride within input vector when computing.
 * @param[out]  Y     Output vector, single complex precision.
 * @param[in]   incY  Stride within output vector when computing.
 *
 */
void
cblas_ccopy(
        const int   N,
        const void  *X,
        const int   incX,
        void        *Y,
        const int   incY
        );


/**
 * @brief Constant times a vector plus a vector, with single complex precision.
 *
 * @details $result = \alpha \cdot X + Y$
 *
 * @param[in]       N       Size of vector.
 * @param[in]       alpha   Alpha to be added, single complex precision.
 * @param[in]       X       Input vector, single complex precision.
 * @param[in]       incX    Stride within input vector when computing.
 * @param[in,out]   Y       Output vector, single complex precision.
 * @param[in]       incY    Stride within output vector when computing.
 *
 */
void
cblas_caxpy(
        const int   N,
        const void  *alpha,
        const void  *X,
        const int   incX,
        void        *Y,
        const int   incY
        );


/**
 * @brief Swap two vectors with double complex precision.
 *
 * @param[in]       N     Size of vector.
 * @param[in,out]   X     Input vector 1, double complex precision.
 * @param[in]       incX  Stride within input vector 1 when computing.
 * @param[in,out]   Y     Input vector 2, double complex precision.
 * @param[in]       incY  Stride within input vector 2 when computing.
 *
 */
void
cblas_zswap(
        const int   N,
        void        *X,
        const int   incX,
        void        *Y,
        const int   incY
        );


/**
 * @brief Copy the content of a vector with double complex precision to another.
 *
 * @param[in]   N     Size of vector.
 * @param[in]   X     Input vector, double complex precision.
 * @param[in]   incX  Stride within input vector when computing.
 * @param[out]  Y     Output vector, double complex precision.
 * @param[in]   incY  Stride within output vector when computing.
 *
 */
void
cblas_zcopy(
        const int   N,
        const void  *X,
        const int   incX,
        void        *Y,
        const int   incY
        );


/**
 * @brief Constant times a vector plus a vector, with double complex precision.
 *
 * @details $result = \alpha \cdot X + Y$
 *
 * @param[in]       N       Size of vector.
 * @param[in]       alpha   Alpha to be added, double complex precision.
 * @param[in]       X       Input vector, double complex precision.
 * @param[in]       incX    Stride within input vector when computing.
 * @param[in,out]   Y       Output vector, double complex precision.
 * @param[in]       incY    Stride within output vector when computing.
 *
 */
void
cblas_zaxpy(
        const int   N,
        const void  *alpha,
        const void  *X,
        const int   incX,
        void        *Y,
        const int   incY
        );


/*
 * Routines with S and D prefix only
 */


/**
 * @brief Compute the *Givens Rotation* of a 2D point (a, b). Single precision.
 *
 * @details *[Givens Rotation](https://en.wikipedia.org/wiki/Givens_rotation)*
 *
 * @param[in,out]   a   First element of the input vector. It is also the
 * parameter $r$ of the *Givens Rotation* after finishing execution:
 * $r = \sqrt{a^{2} + b^{2}}$. Single precision.
 *
 * @param[in,out]   b   Second element of the input vector. It is also the
 * parameter $z$ of the *Givens Rotation* after finishing execution:
 * If $|a| > |b|$, $z$ is $s$, otherwise $c \neq 0 \Rightarrow z = 1 / c$ or
 * $c = 0 \Rightarrow z = 1$. Single precision.
 *
 * @param[in]       c   The parameter $c$ related to the *Givens Rotation*:
 * $c = a / r$. Single precision.
 *
 * @param[in]       s   The parameter $s$ related to the *Givens Rotation*:
 * $s = -b / r$. Single precision.
 *
 */
void
cblas_srotg(
        float *a,
        float *b,
        float *c,
        float *s
        );


/**
 * @brief Given a 2D coordinate of a vector $(x1, y1)$, this function computes
 * the components of a modified Givens transformation matrix H that zeros the
 * $y$-component of the resulting vector. Single precision.
 *
 * @details [x1, 0]^{T} = H \cdot [x1 \cdot \sqrt{d1}, y1 \cdot \sqrt{d2}]^{T}
 *
 * @param[in,out]   d1  The scaling factor for x-coordinate. The first diagonal
 * element of the updated matrix when output. Single precision.
 *
 * @param[in,out]   d2  The scaling factor for y-coordinate. The second diagonal
 * element of the updated matrix when output. Single precision.
 *
 * @param[in,out]   b1  The x-coordinate. The x-coordinate of the rotated vector
 * before scaling. Single precision.
 *
 * @param[in]       b2  The y-coordinate. Single precision.
 * @param[in]       P   An array of length 5. `param[0]` is a flag. The rests
 * are the values in the Givens rotation matrix. The components of $H$ are set
 * as follows:
 *
 * `param[0] == -1.0`: $h_{11} = h_{11}, h_{12} = h_{12}, h_{21} = h_{21},
 * h_{22} = h_{22}$
 *
 * `param[0] == 0.0`: $h_{11} = 1.0, h_{12} = h_{12}, h_{21} = h_{21},
 * h_{22} = 1.0$
 *
 * `param[0] == 1.0`: $h_{11} = h_{11}, h_{12} = 1.0, h_{21} = -1.0,
 * h_{22} = h_{22}$
 *
 * `param[0] == -2.0`: $h_{11} = 1.0, h_{12} = 0.0, h_{21} = 0.0, h_{22} = 1.0$
 *
 */
void
cblas_srotmg(
        float       *d1,
        float       *d2,
        float       *b1,
        const float b2,
        float       *P
        );


/**
 * @brief Given two vectors $X$ and $Y$, replace them with the following result:
 * $x_{i} = c \cdot x_{i} + s \cdot y_{i},
 * y_{i} = c \cdot y_{i} - s \cdot x_{i}$
 *
 * @param[in]       N       The length of vectors $x$ and $y$.
 * @param[in,out]   X       The first input vector. When output, each $x[i]$ is
 * replaced with $c \cdot x_{i} + s \cdot y_{i}$. Single precision.
 *
 * @param[in]       incX    The stride for operations on the elements in X.
 * @param[in,out]   Y       The second input vector. When output, each $x[i]$ is
 * replaced with $c \cdot y_{i} - s \cdot x_{i}$. Single precision.
 *
 * @param[in]       incY    The stride for operations on the elements in Y.
 * @param[in]       c       Scale factor $c$. Single precision.
 * @param[in]       s       Scale factor $s$. Single precision.
 *
 */
void
cblas_srot(
        const int   N,
        float       *X,
        const int   incX,
        float       *Y,
        const int   incY,
        const float c,
        const float s
        );


/**
 * @brief Given two vectors $X$ and $Y$, replace them with the following result:
 * $(x_{i}, y_{i}) = H \codt (x_{i}, y_{i})$, where $i \in \{1, ..., N\}$,
 * $H$ is a modified *Givens Rotation*.
 *
 * @param[in]       N       The length of vectors $x$ and $y$.
 * @param[in,out]   X       The first input vector. When output, each $x[i]$ is
 * replaced with $h_{11} \cdot x[i] + h_{12} \cdot x[i]$. Single precision.
 *
 * @param[in]       incX    The stride for operations on the elements in X.
 * @param[in,out]   Y       The second input vector. When output, each $x[i]$ is
 * replaced with $h_{21} \cdot x[i] + h_{22} \cdot x[i]$. Single precision.
 *
 * @param[in]       incY    The stride for operations on the elements in Y.
 * @param[in]       P       An array of length 5. `param[0]` is a flag. The
 * rests are the values in the Givens rotation matrix. The components of $H$ are
 * set as follows:
 *
 * `param[0] == -1.0`: $h_{11} = h_{11}, h_{12} = h_{12}, h_{21} = h_{21},
 * h_{22} = h_{22}$
 *
 * `param[0] == 0.0`: $h_{11} = 1.0, h_{12} = h_{12}, h_{21} = h_{21},
 * h_{22} = 1.0$
 *
 * `param[0] == 1.0`: $h_{11} = h_{11}, h_{12} = 1.0, h_{21} = -1.0,
 * h_{22} = h_{22}$
 *
 * `param[0] == -2.0`: $h_{11} = 1.0, h_{12} = 0.0, h_{21} = 0.0, h_{22} = 1.0$
 *
 */
void
cblas_srotm(
        const int   N,
        float       *X,
        const int   incX,
        float       *Y,
        const int   incY,
        const float *P
        );

/**
 * @brief Compute the *Givens Rotation* of a 2D point (a, b). Double precision.
 *
 * @details *[Givens Rotation](https://en.wikipedia.org/wiki/Givens_rotation)*
 *
 * @param[in,out]   a   First element of the input vector. It is also the
 * parameter $r$ of the *Givens Rotation* after finishing execution:
 * $r = \sqrt{a^{2} + b^{2}}$. Double precision.
 *
 * @param[in,out]   b   Second element of the input vector. It is also the
 * parameter $z$ of the *Givens Rotation* after finishing execution:
 * If $|a| > |b|$, $z$ is $s$, otherwise $c \neq 0 \Rightarrow z = 1 / c$ or
 * $c = 0 \Rightarrow z = 1$. Double precision.
 *
 * @param[in]       c   The parameter $c$ related to the *Givens Rotation*:
 * $c = a / r$. Double precision.
 *
 * @param[in]       s   The parameter $s$ related to the *Givens Rotation*:
 * $s = -b / r$. Double precision.
 *
 */
void
cblas_drotg(
        double *a,
        double *b,
        double *c,
        double *s
        );


/**
 * @brief Given a 2D coordinate of a vector $(x1, y1)$, this function computes
 * the components of a modified Givens transformation matrix H that zeros the
 * $y$-component of the resulting vector. Double precision.
 *
 * @details [x1, 0]^{T} = H \cdot [x1 \cdot \sqrt{d1}, y1 \cdot \sqrt{d2}]^{T}
 *
 * @param[in,out]   d1  The scaling factor for x-coordinate. The first diagonal
 * element of the updated matrix when output. Double precision.
 *
 * @param[in,out]   d2  The scaling factor for y-coordinate. The second diagonal
 * element of the updated matrix when output. Double precision.
 *
 * @param[in,out]   b1  The x-coordinate. The x-coordinate of the rotated vector
 * before scaling. Double precision.
 *
 * @param[in]       b2  The y-coordinate. Double precision.
 * @param[in]       P   An array of length 5. `param[0]` is a flag. The rests
 * are the values in the Givens rotation matrix. The components of $H$ are set
 * as follows:
 *
 * `param[0] == -1.0`: $h_{11} = h_{11}, h_{12} = h_{12}, h_{21} = h_{21},
 * h_{22} = h_{22}$
 *
 * `param[0] == 0.0`: $h_{11} = 1.0, h_{12} = h_{12}, h_{21} = h_{21},
 * h_{22} = 1.0$
 *
 * `param[0] == 1.0`: $h_{11} = h_{11}, h_{12} = 1.0, h_{21} = -1.0,
 * h_{22} = h_{22}$
 *
 * `param[0] == -2.0`: $h_{11} = 1.0, h_{12} = 0.0, h_{21} = 0.0, h_{22} = 1.0$
 *
 */
void
cblas_drotmg(
        double          *d1,
        double          *d2,
        double          *b1,
        const double    b2,
        double          *P
        );


/**
 * @brief Given two vectors $X$ and $Y$, replace them with the following result:
 * $x_{i} = c \cdot x_{i} + s \cdot y_{i},
 * y_{i} = c \cdot y_{i} - s \cdot x_{i}$
 *
 * @param[in]       N       The length of vectors $x$ and $y$.
 * @param[in,out]   X       The first input vector. When output, each $x[i]$ is
 * replaced with $c \cdot x_{i} + s \cdot y_{i}$. Double precision.
 *
 * @param[in]       incX    The stride for operations on the elements in X.
 * @param[in,out]   Y       The second input vector. When output, each $x[i]$ is
 * replaced with $c \cdot y_{i} - s \cdot x_{i}$. Double precision.
 *
 * @param[in]       incY    The stride for operations on the elements in Y.
 * @param[in]       c       Scale factor $c$. Double precision.
 * @param[in]       s       Scale factor $s$. Double precision.
 *
 */
void
cblas_drot(
        const int       N,
        double          *X,
        const int       incX,
        double          *Y,
        const int       incY,
        const double    c,
        const double    s
        );


/**
 * @brief Given two vectors $X$ and $Y$, replace them with the following result:
 * $(x_{i}, y_{i}) = H \codt (x_{i}, y_{i})$, where $i \in \{1, ..., N\}$,
 * $H$ is a modified *Givens Rotation*.
 *
 * @param[in]       N       The length of vectors $x$ and $y$.
 * @param[in,out]   X       The first input vector. When output, each $x[i]$ is
 * replaced with $h_{11} \cdot x[i] + h_{12} \cdot x[i]$. Double precision.
 *
 * @param[in]       incX    The stride for operations on the elements in X.
 * @param[in,out]   Y       The second input vector. When output, each $x[i]$ is
 * replaced with $h_{21} \cdot x[i] + h_{22} \cdot x[i]$. Double precision.
 *
 * @param[in]       incY    The stride for operations on the elements in Y.
 * @param[in]       P       An array of length 5. `param[0]` is a flag. The
 * rests are the values in the Givens rotation matrix. The components of $H$ are
 * set as follows:
 *
 * `param[0] == -1.0`: $h_{11} = h_{11}, h_{12} = h_{12}, h_{21} = h_{21},
 * h_{22} = h_{22}$
 *
 * `param[0] == 0.0`: $h_{11} = 1.0, h_{12} = h_{12}, h_{21} = h_{21},
 * h_{22} = 1.0$
 *
 * `param[0] == 1.0`: $h_{11} = h_{11}, h_{12} = 1.0, h_{21} = -1.0,
 * h_{22} = h_{22}$
 *
 * `param[0] == -2.0`: $h_{11} = 1.0, h_{12} = 0.0, h_{21} = 0.0, h_{22} = 1.0$
 *
 */
void
cblas_drotm(
        const int       N,
        double          *X,
        const int       incX,
        double          *Y,
        const int       incY,
        const double    *P
        );


/*
 * Routines with S D C Z CS and ZD prefixes
 */


/**
 * @brief Rescale a vector with single precision.
 *
 * @details $result = \alpha \cdot X$
 *
 * @param[in]       N       Size of vector.
 * @param[in]       alpha   Scale factor, single precision.
 * @param[in,out]   X       Input vector, single precision.
 * @param[in]       incX    Stride within input vector when computing.
 *
 */
void
cblas_sscal(
        const int   N,
        const float alpha,
        float       *X,
        const int   incX
        );


/**
 * @brief Rescale a vector with double precision.
 *
 * @details $result = \alpha \cdot X$
 *
 * @param[in]       N       Size of vector.
 * @param[in]       alpha   Scale factor, double precision.
 * @param[in,out]   X       Input vector, double precision.
 * @param[in]       incX    Stride within input vector when computing.
 *
 */
void
cblas_dscal(
        const int       N,
        const double    alpha,
        double          *X,
        const int       incX
        );


/**
 * @brief Rescale a vector with single complex precision.
 *
 * @details $result = \alpha \cdot X$
 *
 * @param[in]       N       Size of vector.
 * @param[in]       alpha   Scale factor, single complex precision.
 * @param[in,out]   X       Input vector, single complex precision.
 * @param[in]       incX    Stride within input vector when computing.
 *
 */
void
cblas_cscal(
        const int   N,
        const void  *alpha,
        void        *X,
        const int   incX
        );


/**
 * @brief Rescale a vector with double complex precision.
 *
 * @details $result = \alpha \cdot X$
 *
 * @param[in]       N       Size of vector.
 * @param[in]       alpha   Scale factor, double complex precision.
 * @param[in,out]   X       Input vector, double complex precision.
 * @param[in]       incX    Stride within input vector when computing.
 *
 */
void
cblas_zscal(
        const int   N,
        const void  *alpha,
        void        *X,
        const int   incX
        );


/**
 * @brief Rescale and reduce a single complex vector.
 *
 * @details $result = \alpha \cdot x_{n} + (0.0 * y)i$, where $x_{n}$ is the
 * real part of the $n$-th element of vector $X$, $y$ is the imaginary part.
 *
 * @param[in]       N       Size of vector.
 * @param[in]       alpha   Scale factor, single complex precision.
 * @param[in,out]   X       Input vector, single complex precision (But
 * the result's imaginary parts are 0).
 * @param[in]       incX    Stride within input vector when computing.
 *
 */
void
cblas_csscal(
        const int   N,
        const float alpha,
        void        *X,
        const int   incX
        );


/**
 * @brief Rescale and reduce a double complex vector.
 *
 * @details $result = \alpha \cdot x_{n} + (0.0 * y)i$, where $x_{n}$ is the
 * real part of the $n$-th element of vector $X$, $y$ is the imaginary part.
 *
 * @param[in]       N       Size of vector.
 * @param[in]       alpha   Scale factor, double complex precision.
 * @param[in,out]   X       Input vector, double complex precision (But
 * the result's imaginary parts are 0).
 * @param[in]       incX    Stride within input vector when computing.
 *
 */
void
cblas_zdscal(
        const int       N,
        const double    alpha,
        void            *X,
        const int       incX
        );



/*
 * ===========================================================================
 * Prototypes for level 2 BLAS
 * ===========================================================================
 */

/*
 * Routines with standard 4 prefixes (S, D, C, Z)
 */
void cblas_sgemv(const enum CBLAS_ORDER order,
                 const enum CBLAS_TRANSPOSE TransA, const int M, const int N,
                 const float alpha, const float *A, const int lda,
                 const float *X, const int incX, const float beta,
                 float *Y, const int incY);
void cblas_sgbmv(const enum CBLAS_ORDER order,
                 const enum CBLAS_TRANSPOSE TransA, const int M, const int N,
                 const int KL, const int KU, const float alpha,
                 const float *A, const int lda, const float *X,
                 const int incX, const float beta, float *Y, const int incY);
void cblas_strmv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo,
                 const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag,
                 const int N, const float *A, const int lda,
                 float *X, const int incX);
void cblas_stbmv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo,
                 const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag,
                 const int N, const int K, const float *A, const int lda,
                 float *X, const int incX);
void cblas_stpmv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo,
                 const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag,
                 const int N, const float *Ap, float *X, const int incX);
void cblas_strsv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo,
                 const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag,
                 const int N, const float *A, const int lda, float *X,
                 const int incX);
void cblas_stbsv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo,
                 const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag,
                 const int N, const int K, const float *A, const int lda,
                 float *X, const int incX);
void cblas_stpsv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo,
                 const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag,
                 const int N, const float *Ap, float *X, const int incX);

void cblas_dgemv(const enum CBLAS_ORDER order,
                 const enum CBLAS_TRANSPOSE TransA, const int M, const int N,
                 const double alpha, const double *A, const int lda,
                 const double *X, const int incX, const double beta,
                 double *Y, const int incY);
void cblas_dgbmv(const enum CBLAS_ORDER order,
                 const enum CBLAS_TRANSPOSE TransA, const int M, const int N,
                 const int KL, const int KU, const double alpha,
                 const double *A, const int lda, const double *X,
                 const int incX, const double beta, double *Y, const int incY);
void cblas_dtrmv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo,
                 const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag,
                 const int N, const double *A, const int lda,
                 double *X, const int incX);
void cblas_dtbmv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo,
                 const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag,
                 const int N, const int K, const double *A, const int lda,
                 double *X, const int incX);
void cblas_dtpmv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo,
                 const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag,
                 const int N, const double *Ap, double *X, const int incX);
void cblas_dtrsv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo,
                 const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag,
                 const int N, const double *A, const int lda, double *X,
                 const int incX);
void cblas_dtbsv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo,
                 const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag,
                 const int N, const int K, const double *A, const int lda,
                 double *X, const int incX);
void cblas_dtpsv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo,
                 const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag,
                 const int N, const double *Ap, double *X, const int incX);

void cblas_cgemv(const enum CBLAS_ORDER order,
                 const enum CBLAS_TRANSPOSE TransA, const int M, const int N,
                 const void *alpha, const void *A, const int lda,
                 const void *X, const int incX, const void *beta,
                 void *Y, const int incY);
void cblas_cgbmv(const enum CBLAS_ORDER order,
                 const enum CBLAS_TRANSPOSE TransA, const int M, const int N,
                 const int KL, const int KU, const void *alpha,
                 const void *A, const int lda, const void *X,
                 const int incX, const void *beta, void *Y, const int incY);
void cblas_ctrmv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo,
                 const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag,
                 const int N, const void *A, const int lda,
                 void *X, const int incX);
void cblas_ctbmv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo,
                 const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag,
                 const int N, const int K, const void *A, const int lda,
                 void *X, const int incX);
void cblas_ctpmv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo,
                 const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag,
                 const int N, const void *Ap, void *X, const int incX);
void cblas_ctrsv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo,
                 const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag,
                 const int N, const void *A, const int lda, void *X,
                 const int incX);
void cblas_ctbsv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo,
                 const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag,
                 const int N, const int K, const void *A, const int lda,
                 void *X, const int incX);
void cblas_ctpsv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo,
                 const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag,
                 const int N, const void *Ap, void *X, const int incX);

void cblas_zgemv(const enum CBLAS_ORDER order,
                 const enum CBLAS_TRANSPOSE TransA, const int M, const int N,
                 const void *alpha, const void *A, const int lda,
                 const void *X, const int incX, const void *beta,
                 void *Y, const int incY);
void cblas_zgbmv(const enum CBLAS_ORDER order,
                 const enum CBLAS_TRANSPOSE TransA, const int M, const int N,
                 const int KL, const int KU, const void *alpha,
                 const void *A, const int lda, const void *X,
                 const int incX, const void *beta, void *Y, const int incY);
void cblas_ztrmv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo,
                 const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag,
                 const int N, const void *A, const int lda,
                 void *X, const int incX);
void cblas_ztbmv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo,
                 const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag,
                 const int N, const int K, const void *A, const int lda,
                 void *X, const int incX);
void cblas_ztpmv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo,
                 const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag,
                 const int N, const void *Ap, void *X, const int incX);
void cblas_ztrsv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo,
                 const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag,
                 const int N, const void *A, const int lda, void *X,
                 const int incX);
void cblas_ztbsv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo,
                 const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag,
                 const int N, const int K, const void *A, const int lda,
                 void *X, const int incX);
void cblas_ztpsv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo,
                 const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag,
                 const int N, const void *Ap, void *X, const int incX);


/*
 * Routines with S and D prefixes only
 */
void cblas_ssymv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo,
                 const int N, const float alpha, const float *A,
                 const int lda, const float *X, const int incX,
                 const float beta, float *Y, const int incY);
void cblas_ssbmv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo,
                 const int N, const int K, const float alpha, const float *A,
                 const int lda, const float *X, const int incX,
                 const float beta, float *Y, const int incY);
void cblas_sspmv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo,
                 const int N, const float alpha, const float *Ap,
                 const float *X, const int incX,
                 const float beta, float *Y, const int incY);
void cblas_sger(const enum CBLAS_ORDER order, const int M, const int N,
                const float alpha, const float *X, const int incX,
                const float *Y, const int incY, float *A, const int lda);
void cblas_ssyr(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo,
                const int N, const float alpha, const float *X,
                const int incX, float *A, const int lda);
void cblas_sspr(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo,
                const int N, const float alpha, const float *X,
                const int incX, float *Ap);
void cblas_ssyr2(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo,
                const int N, const float alpha, const float *X,
                const int incX, const float *Y, const int incY, float *A,
                const int lda);
void cblas_sspr2(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo,
                const int N, const float alpha, const float *X,
                const int incX, const float *Y, const int incY, float *A);

void cblas_dsymv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo,
                 const int N, const double alpha, const double *A,
                 const int lda, const double *X, const int incX,
                 const double beta, double *Y, const int incY);
void cblas_dsbmv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo,
                 const int N, const int K, const double alpha, const double *A,
                 const int lda, const double *X, const int incX,
                 const double beta, double *Y, const int incY);
void cblas_dspmv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo,
                 const int N, const double alpha, const double *Ap,
                 const double *X, const int incX,
                 const double beta, double *Y, const int incY);
void cblas_dger(const enum CBLAS_ORDER order, const int M, const int N,
                const double alpha, const double *X, const int incX,
                const double *Y, const int incY, double *A, const int lda);
void cblas_dsyr(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo,
                const int N, const double alpha, const double *X,
                const int incX, double *A, const int lda);
void cblas_dspr(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo,
                const int N, const double alpha, const double *X,
                const int incX, double *Ap);
void cblas_dsyr2(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo,
                const int N, const double alpha, const double *X,
                const int incX, const double *Y, const int incY, double *A,
                const int lda);
void cblas_dspr2(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo,
                const int N, const double alpha, const double *X,
                const int incX, const double *Y, const int incY, double *A);


/*
 * Routines with C and Z prefixes only
 */
void cblas_chemv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo,
                 const int N, const void *alpha, const void *A,
                 const int lda, const void *X, const int incX,
                 const void *beta, void *Y, const int incY);
void cblas_chbmv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo,
                 const int N, const int K, const void *alpha, const void *A,
                 const int lda, const void *X, const int incX,
                 const void *beta, void *Y, const int incY);
void cblas_chpmv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo,
                 const int N, const void *alpha, const void *Ap,
                 const void *X, const int incX,
                 const void *beta, void *Y, const int incY);
void cblas_cgeru(const enum CBLAS_ORDER order, const int M, const int N,
                 const void *alpha, const void *X, const int incX,
                 const void *Y, const int incY, void *A, const int lda);
void cblas_cgerc(const enum CBLAS_ORDER order, const int M, const int N,
                 const void *alpha, const void *X, const int incX,
                 const void *Y, const int incY, void *A, const int lda);
void cblas_cher(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo,
                const int N, const float alpha, const void *X, const int incX,
                void *A, const int lda);
void cblas_chpr(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo,
                const int N, const float alpha, const void *X,
                const int incX, void *A);
void cblas_cher2(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N,
                const void *alpha, const void *X, const int incX,
                const void *Y, const int incY, void *A, const int lda);
void cblas_chpr2(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N,
                const void *alpha, const void *X, const int incX,
                const void *Y, const int incY, void *Ap);

void cblas_zhemv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo,
                 const int N, const void *alpha, const void *A,
                 const int lda, const void *X, const int incX,
                 const void *beta, void *Y, const int incY);
void cblas_zhbmv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo,
                 const int N, const int K, const void *alpha, const void *A,
                 const int lda, const void *X, const int incX,
                 const void *beta, void *Y, const int incY);
void cblas_zhpmv(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo,
                 const int N, const void *alpha, const void *Ap,
                 const void *X, const int incX,
                 const void *beta, void *Y, const int incY);
void cblas_zgeru(const enum CBLAS_ORDER order, const int M, const int N,
                 const void *alpha, const void *X, const int incX,
                 const void *Y, const int incY, void *A, const int lda);
void cblas_zgerc(const enum CBLAS_ORDER order, const int M, const int N,
                 const void *alpha, const void *X, const int incX,
                 const void *Y, const int incY, void *A, const int lda);
void cblas_zher(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo,
                const int N, const double alpha, const void *X, const int incX,
                void *A, const int lda);
void cblas_zhpr(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo,
                const int N, const double alpha, const void *X,
                const int incX, void *A);
void cblas_zher2(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N,
                const void *alpha, const void *X, const int incX,
                const void *Y, const int incY, void *A, const int lda);
void cblas_zhpr2(const enum CBLAS_ORDER order, const enum CBLAS_UPLO Uplo, const int N,
                const void *alpha, const void *X, const int incX,
                const void *Y, const int incY, void *Ap);

/*
 * ===========================================================================
 * Prototypes for level 3 BLAS
 * ===========================================================================
 */

/*
 * Routines with standard 4 prefixes (S, D, C, Z)
 */


/**
 * @brief General Matrix-Matrix multiplication, single precision.
 *
 * @details $C = \alpha \cdot op(A) \cdot op(B) + \beta \cdot C$, where
 * $op(X) = X$ or $X^{T}$.
 *
 * @param[in]       Order   The dimension, in which the elements are continuous
 * in memory. When the elements within a row are continuous in memory, then
 * CblasRowMajor should be set, and vice versa. It is used to describe the
 * memory layout of the input matrix, which means the transpose parameters
 * (TransA and TransB) has nothing to do with the major order.
 *
 * @param[in]       TransA  Transpose flag for matrix A. When CblasNoTrans is
 * set, $op(A) = A$. When CblasTrans or CblasConjTrans is set, $op(A) = A^{T}$.
 *
 * @param[in]       TransB  Transpose flag for matrix B. When CblasNoTrans is
 * set, $op(B) = B$. When CblasTrans or CblasConjTrans is set, $op(B) = B^{T}$.
 *
 * @param[in]       M       Number of rows in $op(A)$ and matrix C. It must be
 * at least 0.
 *
 * @param[in]       N       Number of columns in $op(B)$ and matrix C. It must
 * be at least 0.
 *
 * @param[in]       K       Number of columns in $op(A)$, and the number of rows
 * in $op(B)$. It must be at least 0.
 *
 * @param[in]       alpha   Scale for the first matrix, single precision.
 * @param[in]       A       Input matrix A, single precision.
 * @param[in]       lda     The leading dimension of matrix A. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 * @param[in]       B       Input matrix B, single precision.
 * @param[in]       ldb     The leading dimension of matrix B. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 * @param[in]       beta    Scale for the matrix C, single precision.
 * @param[in,out]   C       Result matrix, single precision.
 * @param[in]       ldc     The leading dimension of matrix C. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 */
void
cblas_sgemm(
        const enum CBLAS_ORDER      Order,
        const enum CBLAS_TRANSPOSE  TransA,
        const enum CBLAS_TRANSPOSE  TransB,
        const int                   M,
        const int                   N,
        const int                   K,
        const float                 alpha,
        const float                 *A,
        const int                   lda,
        const float                 *B,
        const int                   ldb,
        const float                 beta,
        float                       *C,
        const int                   ldc
        );


/**
 * @brief Symmetric Matrix-Matrix multiplication, single precision.
 *
 * @details $C = \alpha \cdot op(A) \cdot op(B) + \beta \cdot C$,
 *
 * or
 *
 * $C = \alpha \cdot op(B) \cdot op(A) + \beta \cdot C$,
 *
 * where $op(X) = X$ or $X^{T}$.
 *
 * @param[in]       Order   The dimension, in which the elements are continuous
 * in memory. When the elements within a row are continuous in memory, then
 * CblasRowMajor should be set, and vice versa.
 *
 * @param[in]       Side    Specify the side of $op(A)$ relative to $op(B)$
 * when computing.
 *
 * @param[in]       Uplo    Specify the triangular part to be used in
 * computation (upper triangular part or lower triangular part).
 *
 * @param[in]       M       Number of rows in $op(A)$ and matrix C. It must be
 * at least 0.
 *
 * @param[in]       N       Number of columns in $op(B)$ and matrix C. It must
 * be at least 0.
 *
 * @param[in]       K       Number of columns in $op(A)$, and the number of rows
 * in $op(B)$. It must be at least 0.
 *
 * @param[in]       alpha   Scale for the first matrix, single precision.
 * @param[in]       A       Input matrix A, single precision.
 * @param[in]       lda     The leading dimension of matrix A. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 * @param[in]       B       Input matrix B, single precision.
 * @param[in]       ldb     The leading dimension of matrix B. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 * @param[in]       beta    Scale for the matrix C, single precision.
 * @param[in,out]   C       Result matrix, single precision.
 * @param[in]       ldc     The leading dimension of matrix C. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 */
void
cblas_ssymm(
        const enum CBLAS_ORDER  Order,
        const enum CBLAS_SIDE   Side,
        const enum CBLAS_UPLO   Uplo,
        const int               M,
        const int               N,
        const float             alpha,
        const float             *A,
        const int               lda,
        const float             *B,
        const int               ldb,
        const float             beta,
        float                   *C,
        const int               ldc
        );


/**
 * @brief Perform a rank-k matrix-matrix operation for a symmetric matrix with
 * a general matrix. Single precision.
 *
 * @details $C = \alpha \cdot A \cdot A^{T} + \beta \cdot C$,
 *
 * or
 *
 * $C = \alpha \cdot A^{T} \cdot A + \beta \cdot C$,
 *
 * @param[in]       Order   The dimension, in which the elements are continuous
 * in memory. When the elements within a row are continuous in memory, then
 * CblasRowMajor should be set, and vice versa.
 *
 * @param[in]       Uplo    Specify the triangular part of C to be used in
 * computation (upper triangular part or lower triangular part).
 *
 * @param[in]       Trans   Transpose flag for matrix A. When CblasNoTrans is
 * set, $C = \alpha \cdot A \cdot A^{T} + \beta \cdot C$. When CblasTrans or
 * CblasConjTrans is set $C = \alpha \cdot A^{T} \cdot A + \beta \codt C$.
 *
 * @param[in]       N       The order of matrix C. It must be at least 0. C is a
 * square matrix.
 *
 * @param[in]       K       Number of columns in $op(A)$. It must be at least 0.
 *
 * @param[in]       alpha   Scale for matrix A, single precision.
 * @param[in]       A       Input matrix A, single precision.
 * @param[in]       lda     The leading dimension of matrix A. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 * @param[in]       beta    Scale for the matrix C, single precision.
 * @param[in,out]   C       Result matrix, single precision.
 * @param[in]       ldc     The leading dimension of matrix C. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 */
void
cblas_ssyrk(
        const enum CBLAS_ORDER      Order,
        const enum CBLAS_UPLO       Uplo,
        const enum CBLAS_TRANSPOSE  Trans,
        const int                   N,
        const int                   K,
        const float                 alpha,
        const float                 *A,
        const int                   lda,
        const float                 beta,
        float                       *C,
        const int                   ldc
        );


/**
 * @brief Perform a rank-2 matrix-matrix operation for a symmetric matrix with
 * two general matrix. Single precision.
 *
 * @details $C = \alpha \cdot A \cdot B^{T} + \alpha \cdot B \cdot A^{T}
 * + \beta \cdot C$,
 *
 * or
 *
 * $C = \alpha \cdot A^{T} \cdot B + \alpha \cdot B^{T} \cdot A + \beta \cdot C$
 *
 * @param[in]       Order   The dimension, in which the elements are continuous
 * in memory. When the elements within a row are continuous in memory, then
 * CblasRowMajor should be set, and vice versa.
 *
 * @param[in]       Uplo    Specify the triangular part of C to be used in
 * computation (upper triangular part or lower triangular part).
 *
 * @param[in]       Trans   Transpose flag for matrix A.
 * When CblasNoTrans is set,
 * $C = \alpha \cdot A \cdot B^{T} + \alpha \cdot B \cdot A^{T} + \beta \cdot C$
 * When CblasConjTrans is set,
 * $C = \alpha \cdot A^{T} \cdot B + \alpha \cdot B^{T} \cdot A + \beta \cdot C$
 *
 * @param[in]       N       The order of matrix C. It must be at least 0. C is a
 * square matrix.
 *
 * @param[in]       K       Number of columns in $op(A)$. It must be at least 0.
 *
 * @param[in]       alpha   Scale, single precision.
 * @param[in]       A       Input matrix A, single precision.
 * @param[in]       lda     The leading dimension of matrix A. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 * @param[in]       B       Input matrix B, single precision.
 * @param[in]       ldb     The leading dimension of matrix B. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 * @param[in]       beta    Scale for the matrix C, single precision.
 * @param[in,out]   C       Result matrix, single precision.
 * @param[in]       ldc     The leading dimension of matrix C. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 */
void
cblas_ssyr2k(
        const enum CBLAS_ORDER      Order,
        const enum CBLAS_UPLO       Uplo,
        const enum CBLAS_TRANSPOSE  Trans,
        const int                   N,
        const int                   K,
        const float                 alpha,
        const float                 *A,
        const int                   lda,
        const float                 *B,
        const int                   ldb,
        const float                 beta,
        float                       *C,
        const int                   ldc
        );


/**
 * @brief Matrix-matrix product with one triangular matrix, single precision.
 *
 * @details $B = \alpha \cdot op(A) \cdot B$
 *
 * or
 *
 * $B = \alpha \cdot B \cdot op(A)$
 *
 * @param[in]       Order   The dimension, in which the elements are continuous
 * in memory. When the elements within a row are continuous in memory, then
 * CblasRowMajor should be set, and vice versa.
 *
 * @param[in]       Side    Specify the side of $op(A)$ relative to B.
 * @param[in]       Uplo    Specify whether the matrix A is upper triangular or
 * lower triangular.
 *
 * @param[in]       TransA  Transpose flag for matrix A.
 * When CblasNoTrans is set, $op(A) = A$. When CblasTrans or CblasConjTrans is
 * set, $op(A) = A^{T}$.
 *
 * @param[in]       Diag    Specifies whether matrix A is unit triangular.
 *
 * @param[in]       M       The number of rows of matrix B. It must be at least
 * zero.
 *
 * @param[in]       N       The number of column of matrix B. It must be at
 * least zero.
 *
 * @param[in]       alpha   Scale, single precision.
 * @param[in]       A       Input matrix A, single precision.
 * @param[in]       lda     The leading dimension of matrix A. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 * @param[in,out]   B       Input and result matrix B, single precision.
 * @param[in]       ldb     The leading dimension of matrix B. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 */
void
cblas_strmm(
        const enum CBLAS_ORDER      Order,
        const enum CBLAS_SIDE       Side,
        const enum CBLAS_UPLO       Uplo,
        const enum CBLAS_TRANSPOSE  TransA,
        const enum CBLAS_DIAG       Diag,
        const int                   M,
        const int                   N,
        const float                 alpha,
        const float                 *A,
        const int                   lda,
        float                       *B,
        const int                   ldb
        );


/**
 * @brief This function is used to solve the X in the following equation,
 * single precision.
 *
 * @details $op(A) \cdot X = \alpha \cdot B$
 *
 * or
 *
 * $X \cdot op(A) = \alpha \cdot B$
 *
 * @param[in]       Order   The dimension, in which the elements are continuous
 * in memory. When the elements within a row are continuous in memory, then
 * CblasRowMajor should be set, and vice versa. It is used to describe the
 * memory layout of the input matrix, which means the transpose parameters
 * (TransA and TransB) has nothing to do with the major order.
 *
 * @param[in]       Side    Specify the side of $op(A)$ relative to X.
 * @param[in]       Uplo    Specify whether the matrix A is upper triangular or
 * lower triangular.
 *
 * @param[in]       TransA  Transpose flag for matrix A.
 * When CblasNoTrans is set, $op(A) = A$. When CblasTrans or CblasConjTrans is
 * set, $op(A) = A^{T}$.
 *
 * @param[in]       Diag    Specifies whether matrix A is unit triangular.
 *
 * @param[in]       M       The number of rows of matrix B. It must be at least
 * zero.
 *
 * @param[in]       N       The number of column of matrix B. It must be at
 * least zero.
 *
 * @param[in]       alpha   Scale, single precision.
 * @param[in]       A       Input matrix A, single precision.
 * @param[in]       lda     The leading dimension of matrix A. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 * @param[in,out]   B       Input and result matrix B, single precision.
 * @param[in]       ldb     The leading dimension of matrix B. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 */
void
cblas_strsm(
        const enum CBLAS_ORDER      Order,
        const enum CBLAS_SIDE       Side,
        const enum CBLAS_UPLO       Uplo,
        const enum CBLAS_TRANSPOSE  TransA,
        const enum CBLAS_DIAG       Diag,
        const int                   M,
        const int                   N,
        const float                 alpha,
        const float                 *A,
        const int                   lda,
        float                       *B,
        const int                   ldb
        );


/**
 * @brief General Matrix-Matrix multiplication, double precision.
 *
 * @details $C = \alpha \cdot op(A) \cdot op(B) + \beta \cdot C$, where
 * $op(X) = X$ or $X^{T}$.
 *
 * @param[in]       Order   The dimension, in which the elements are continuous
 * in memory. When the elements within a row are continuous in memory, then
 * CblasRowMajor should be set, and vice versa. It is used to describe the
 * memory layout of the input matrix, which means the transpose parameters
 * (TransA and TransB) has nothing to do with the major order.
 *
 * @param[in]       TransA  Transpose flag for matrix A. When CblasNoTrans is
 * set, $op(A) = A$. When CBlasTrans or CBlasConjTrans is set, $op(A) = A^{T}$.
 *
 * @param[in]       TransB  Transpose flag for matrix B. When CblasNoTrans is
 * set, $op(B) = B$. When CBlasTrans or CBlasConjTrans is set, $op(B) = B^{T}$.
 *
 * @param[in]       M       Number of rows in $op(A)$ and matrix C. It must be
 * at least 0.
 *
 * @param[in]       N       Number of columns in $op(B)$ and matrix C. It must
 * be at least 0.
 *
 * @param[in]       K       Number of columns in $op(A)$, and the number of rows
 * in $op(B)$. It must be at least 0.
 *
 * @param[in]       alpha   Scale for the first matrix, double precision.
 * @param[in]       A       Input matrix A, double precision.
 * @param[in]       lda     The leading dimension of matrix A. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 * @param[in]       B       Input matrix B, double precision.
 * @param[in]       ldb     The leading dimension of matrix B. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 * @param[in]       beta    Scale for the matrix C, double precision.
 * @param[in,out]   C       Result matrix, double precision.
 * @param[in]       ldc     The leading dimension of matrix C. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 */
void
cblas_dgemm(
        const enum CBLAS_ORDER      Order,
        const enum CBLAS_TRANSPOSE  TransA,
        const enum CBLAS_TRANSPOSE  TransB,
        const int                   M,
        const int                   N,
        const int                   K,
        const double                alpha,
        const double                *A,
        const int                   lda,
        const double                *B,
        const int                   ldb,
        const double                beta,
        double                      *C,
        const int                   ldc
        );


/**
 * @brief Symmetric Matrix-Matrix multiplication, double precision.
 *
 * @details $C = \alpha \cdot op(A) \cdot op(B) + \beta \cdot C$,
 *
 * or
 *
 * $C = \alpha \cdot op(B) \cdot op(A) + \beta \cdot C$,
 *
 * where $op(X) = X$ or $X^{T}$.
 *
 * @param[in]       Order   The dimension, in which the elements are continuous
 * in memory. When the elements within a row are continuous in memory, then
 * CblasRowMajor should be set, and vice versa.
 *
 * @param[in]       Side    Specify the side of $op(A)$ relative to $op(B)$
 * when computing.
 *
 * @param[in]       Uplo    Specify the triangular part to be used in
 * computation (upper triangular part or lower triangular part).
 *
 * @param[in]       M       Number of rows in $op(A)$ and matrix C. It must be
 * at least 0.
 *
 * @param[in]       N       Number of columns in $op(B)$ and matrix C. It must
 * be at least 0.
 *
 * @param[in]       K       Number of columns in $op(A)$, and the number of rows
 * in $op(B)$. It must be at least 0.
 *
 * @param[in]       alpha   Scale for the first matrix, double precision.
 * @param[in]       A       Input matrix A, double precision.
 * @param[in]       lda     The leading dimension of matrix A. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 * @param[in]       B       Input matrix B, double precision.
 * @param[in]       ldb     The leading dimension of matrix B. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 * @param[in]       beta    Scale for the matrix C, double precision.
 * @param[in,out]   C       Result matrix, double precision.
 * @param[in]       ldc     The leading dimension of matrix C. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 */
void
cblas_dsymm(
        const enum CBLAS_ORDER  Order,
        const enum CBLAS_SIDE   Side,
        const enum CBLAS_UPLO   Uplo,
        const int               M,
        const int               N,
        const double            alpha,
        const double            *A,
        const int               lda,
        const double            *B,
        const int               ldb,
        const double            beta,
        double                  *C,
        const int               ldc
        );


/**
 * @brief Perform a rank-k matrix-matrix operation for a symmetric matrix with
 * a general matrix. Double precision.
 *
 * @details $C = \alpha \cdot A \cdot A^{T} + \beta \cdot C$,
 *
 * or
 *
 * $C = \alpha \cdot A^{T} \cdot A + \beta \cdot C$,
 *
 * @param[in]       Order   The dimension, in which the elements are continuous
 * in memory. When the elements within a row are continuous in memory, then
 * CblasRowMajor should be set, and vice versa.
 *
 * @param[in]       Uplo    Specify the triangular part of C to be used in
 * computation (upper triangular part or lower triangular part).
 *
 * @param[in]       Trans   Transpose flag for matrix A. When CblasNoTrans is
 * set, $C = \alpha \cdot A \cdot A^{T} + \beta \cdot C$. When CblasTrans or
 * CblasConjTrans is set $C = \alpha \cdot A^{T} \cdot A + \beta \codt C$.
 *
 * @param[in]       N       The order of matrix C. It must be at least 0. C is a
 * square matrix.
 *
 * @param[in]       K       Number of columns in $op(A)$. It must be at least 0.
 *
 * @param[in]       alpha   Scale for matrix A, double precision.
 * @param[in]       A       Input matrix A, double precision.
 * @param[in]       lda     The leading dimension of matrix A. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 * @param[in]       beta    Scale for the matrix C, double precision.
 * @param[in,out]   C       Result matrix, double precision.
 * @param[in]       ldc     The leading dimension of matrix C. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 */
void
cblas_dsyrk(
        const enum CBLAS_ORDER      Order,
        const enum CBLAS_UPLO       Uplo,
        const enum CBLAS_TRANSPOSE  Trans,
        const int                   N,
        const int                   K,
        const double                alpha,
        const double                *A,
        const int                   lda,
        const double                beta,
        double                      *C,
        const int                   ldc
        );


/**
 * @brief Perform a rank-2 matrix-matrix operation for a symmetric matrix with
 * two general matrix. Double precision.
 *
 * @details $C = \alpha \cdot A \cdot B^{T} + \alpha \cdot B \cdot A^{T}
 * + \beta \cdot C$,
 *
 * or
 *
 * $C = \alpha \cdot A^{T} \cdot B + \alpha \cdot B^{T} \cdot A + \beta \cdot C$
 *
 * @param[in]       Order   The dimension, in which the elements are continuous
 * in memory. When the elements within a row are continuous in memory, then
 * CblasRowMajor should be set, and vice versa.
 *
 * @param[in]       Uplo    Specify the triangular part of C to be used in
 * computation (upper triangular part or lower triangular part).
 *
 * @param[in]       Trans   Transpose flag for matrix A.
 * When CblasNoTrans is set,
 * $C = \alpha \cdot A \cdot B^{T} + \alpha \cdot B \cdot A^{T} + \beta \cdot C$
 * When CblasConjTrans is set,
 * $C = \alpha \cdot A^{T} \cdot B + \alpha \cdot B^{T} \cdot A + \beta \cdot C$
 *
 * @param[in]       N       The order of matrix C. It must be at least 0. C is a
 * square matrix.
 *
 * @param[in]       K       Number of columns in $op(A)$. It must be at least 0.
 *
 * @param[in]       alpha   Scale, double precision.
 * @param[in]       A       Input matrix A, double precision.
 * @param[in]       lda     The leading dimension of matrix A. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 * @param[in]       B       Input matrix B, double precision.
 * @param[in]       ldb     The leading dimension of matrix B. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 * @param[in]       beta    Scale for the matrix C, double precision.
 * @param[in,out]   C       Result matrix, double precision.
 * @param[in]       ldc     The leading dimension of matrix C. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 */
void
cblas_dsyr2k(
        const enum CBLAS_ORDER      Order,
        const enum CBLAS_UPLO       Uplo,
        const enum CBLAS_TRANSPOSE  Trans,
        const int                   N,
        const int                   K,
        const double                alpha,
        const double                *A,
        const int                   lda,
        const double                *B,
        const int                   ldb,
        const double                beta,
        double                      *C,
        const int                   ldc
        );


/**
 * @brief Matrix-matrix product with one triangular matrix, double precision.
 *
 * @details $B = \alpha \cdot op(A) \cdot B$
 *
 * or
 *
 * $B = \alpha \cdot B \cdot op(A)$
 *
 * @param[in]       Order   The dimension, in which the elements are continuous
 * in memory. When the elements within a row are continuous in memory, then
 * CblasRowMajor should be set, and vice versa.
 *
 * @param[in]       Side    Specify the side of $op(A)$ relative to B.
 * @param[in]       Uplo    Specify whether the matrix A is upper triangular or
 * lower triangular.
 *
 * @param[in]       TransA  Transpose flag for matrix A.
 * When CblasNoTrans is set, $op(A) = A$. When CblasTrans or CblasConjTrans is
 * set, $op(A) = A^{T}$.
 *
 * @param[in]       Diag    Specifies whether matrix A is unit triangular.
 *
 * @param[in]       M       The number of rows of matrix B. It must be at least
 * zero.
 *
 * @param[in]       N       The number of column of matrix B. It must be at
 * least zero.
 *
 * @param[in]       alpha   Scale, double precision.
 * @param[in]       A       Input matrix A, double precision.
 * @param[in]       lda     The leading dimension of matrix A. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 * @param[in,out]   B       Input and result matrix B, double precision.
 * @param[in]       ldb     The leading dimension of matrix B. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 */
void
cblas_dtrmm(
        const enum CBLAS_ORDER      Order,
        const enum CBLAS_SIDE       Side,
        const enum CBLAS_UPLO       Uplo,
        const enum CBLAS_TRANSPOSE  TransA,
        const enum CBLAS_DIAG       Diag,
        const int                   M,
        const int                   N,
        const double                alpha,
        const double                *A,
        const int                   lda,
        double                      *B,
        const int                   ldb
        );


/**
 * @brief This function is used to solve the X in the following equation,
 * double precision.
 *
 * @details $op(A) \cdot X = \alpha \cdot B$
 *
 * or
 *
 * $X \cdot op(A) = \alpha \cdot B$
 *
 * @param[in]       Order   The dimension, in which the elements are continuous
 * in memory. When the elements within a row are continuous in memory, then
 * CblasRowMajor should be set, and vice versa.
 *
 * @param[in]       Side    Specify the side of $op(A)$ relative to X.
 * @param[in]       Uplo    Specify whether the matrix A is upper triangular or
 * lower triangular.
 *
 * @param[in]       TransA  Transpose flag for matrix A.
 * When CblasNoTrans is set, $op(A) = A$. When CblasTrans or CblasConjTrans is
 * set, $op(A) = A^{T}$.
 *
 * @param[in]       Diag    Specifies whether matrix A is unit triangular.
 *
 * @param[in]       M       The number of rows of matrix B. It must be at least
 * zero.
 *
 * @param[in]       N       The number of column of matrix B. It must be at
 * least zero.
 *
 * @param[in]       alpha   Scale, double precision.
 * @param[in]       A       Input matrix A, double precision.
 * @param[in]       lda     The leading dimension of matrix A. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 * @param[in,out]   B       Input and result matrix B, double precision.
 * @param[in]       ldb     The leading dimension of matrix B. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 */
void
cblas_dtrsm(
        const enum CBLAS_ORDER      Order,
        const enum CBLAS_SIDE       Side,
        const enum CBLAS_UPLO       Uplo,
        const enum CBLAS_TRANSPOSE  TransA,
        const enum CBLAS_DIAG       Diag,
        const int                   M,
        const int                   N,
        const double                alpha,
        const double                *A,
        const int                   lda,
        double                      *B,
        const int                   ldb
        );


/**
 * @brief General Matrix-Matrix multiplication, single complex precision.
 *
 * @details $C = \alpha \cdot op(A) \cdot op(B) + \beta \cdot C$, where
 * $op(X) = X$ or $X^{T}$.
 *
 * @param[in]       Order   The dimension, in which the elements are continuous
 * in memory. When the elements within a row are continuous in memory, then
 * CblasRowMajor should be set, and vice versa. It is used to describe the
 * memory layout of the input matrix, which means the transpose parameters
 * (TransA and TransB) has nothing to do with the major order.
 *
 * @param[in]       TransA  Transpose flag for matrix A. When CblasNoTrans is
 * set, $op(A) = A$. When CBlasTrans is set, $op(A) = A^{T}$. When
 * CBlasConjTrans is set, $op(A) = A^{*}$, the conjugating transpose.
 *
 * @param[in]       TransB  Transpose flag for matrix B. When CblasNoTrans is
 * set, $op(B) = B$. When CBlasTrans is set, $op(B) = B^{T}$. When
 * CBlasConjTrans is set, $op(B) = B^{*}$, the conjugating transpose.
 *
 * @param[in]       M       Number of rows in $op(A)$ and matrix C. It must be
 * at least 0.
 *
 * @param[in]       N       Number of columns in $op(B)$ and matrix C. It must
 * be at least 0.
 *
 * @param[in]       K       Number of columns in $op(A)$, and the number of rows
 * in $op(B)$. It must be at least 0.
 *
 * @param[in]       alpha   Scale for the first matrix, single complex
 * precision. To be noticed is that, this parameter is a pointer pointing to a
 * single complex number, unlike in cblas_sgemm and cblas_dgemm.
 *
 * @param[in]       A       Input matrix A, single complex precision.
 * @param[in]       lda     The leading dimension of matrix A. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 * @param[in]       B       Input matrix B, single complex precision.
 * @param[in]       ldb     The leading dimension of matrix B. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 * @param[in]       beta    Scale for the matrix C, single complex precision. To
 * be noticed is that, this parameter is a pointer pointing to a single complex
 * number, unlike in cblas_sgemm and cblas_dgemm.
 *
 * @param[in,out]   C       Result matrix, single complex precision.
 * @param[in]       ldc     The leading dimension of matrix C. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 */
void
cblas_cgemm(
        const enum CBLAS_ORDER      Order,
        const enum CBLAS_TRANSPOSE  TransA,
        const enum CBLAS_TRANSPOSE  TransB,
        const int                   M,
        const int                   N,
        const int                   K,
        const void                  *alpha,
        const void                  *A,
        const int                   lda,
        const void                  *B,
        const int                   ldb,
        const void                  *beta,
        void                        *C,
        const int                   ldc
        );


/**
 * @brief Symmetric Matrix-Matrix multiplication, single complex precision.
 *
 * @details $C = \alpha \cdot op(A) \cdot op(B) + \beta \cdot C$,
 *
 * or
 *
 * $C = \alpha \cdot op(B) \cdot op(A) + \beta \cdot C$,
 *
 * where $op(X) = X$ or $X^{T}$.
 *
 * @param[in]       Order   The dimension, in which the elements are continuous
 * in memory. When the elements within a row are continuous in memory, then
 * CblasRowMajor should be set, and vice versa.
 *
 * @param[in]       Side    Specify the side of $op(A)$ relative to $op(B)$
 * when computing.
 *
 * @param[in]       Uplo    Specify the triangular part to be used in
 * computation (upper triangular part or lower triangular part).
 *
 * @param[in]       M       Number of rows in $op(A)$ and matrix C. It must be
 * at least 0.
 *
 * @param[in]       N       Number of columns in $op(B)$ and matrix C. It must
 * be at least 0.
 *
 * @param[in]       K       Number of columns in $op(A)$, and the number of rows
 * in $op(B)$. It must be at least 0.
 *
 * @param[in]       alpha   Scale for the first matrix, single complex
 * precision. To be noticed is that, this parameter is a pointer pointing to a
 * single complex number, unlike in cblas_sgemm and cblas_dgemm.
 *
 * @param[in]       A       Input matrix A, single complex precision.
 * @param[in]       lda     The leading dimension of matrix A. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 * @param[in]       B       Input matrix B, single complex precision.
 * @param[in]       ldb     The leading dimension of matrix B. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 * @param[in]       beta    Scale for the matrix C, single complex precision. To
 * be noticed is that, this parameter is a pointer pointing to a single complex
 * number, unlike in cblas_sgemm and cblas_dgemm.
 *
 * @param[in,out]   C       Result matrix, single complex precision.
 * @param[in]       ldc     The leading dimension of matrix C. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 */
void
cblas_csymm(
        const enum CBLAS_ORDER  Order,
        const enum CBLAS_SIDE   Side,
        const enum CBLAS_UPLO   Uplo,
        const int               M,
        const int               N,
        const void              *alpha,
        const void              *A,
        const int               lda,
        const void              *B,
        const int               ldb,
        const void              *beta,
        void                    *C,
        const int               ldc
        );


/**
 * @brief Perform a rank-k matrix-matrix operation for a symmetric matrix with
 * a general matrix. Single complex precision.
 *
 * @details $C = \alpha \cdot A \cdot A^{T} + \beta \cdot C$,
 *
 * or
 *
 * $C = \alpha \cdot A^{T} \cdot A + \beta \cdot C$,
 *
 * @param[in]       Order   The dimension, in which the elements are continuous
 * in memory. When the elements within a row are continuous in memory, then
 * CblasRowMajor should be set, and vice versa.
 *
 * @param[in]       Uplo    Specify the triangular part of C to be used in
 * computation (upper triangular part or lower triangular part).
 *
 * @param[in]       Trans   Transpose flag for matrix A. When CblasNoTrans is
 * set, $C = \alpha \cdot A \cdot A^{T} + \beta \cdot C$. When CblasTrans or
 * CblasConjTrans is set $C = \alpha \cdot A^{T} \cdot A + \beta \codt C$.
 *
 * @param[in]       N       The order of matrix C. It must be at least 0. C is a
 * square matrix.
 *
 * @param[in]       K       Number of columns in $op(A)$. It must be at least 0.
 *
 * @param[in]       alpha   Scale for matrix A, single complex precision.
 * @param[in]       A       Input matrix A, single complex precision.
 * @param[in]       lda     The leading dimension of matrix A. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 * @param[in]       beta    Scale for the matrix C, single complex precision.
 * @param[in,out]   C       Result matrix, single complex precision.
 * @param[in]       ldc     The leading dimension of matrix C. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 */
void
cblas_csyrk(
        const enum CBLAS_ORDER      Order,
        const enum CBLAS_UPLO       Uplo,
        const enum CBLAS_TRANSPOSE  Trans,
        const int                   N,
        const int                   K,
        const void                  *alpha,
        const void                  *A,
        const int                   lda,
        const void                  *beta,
        void                        *C,
        const int                   ldc
        );


/**
 * @brief Perform a rank-2 matrix-matrix operation for a symmetric matrix with
 * two general matrix. Single complex precision.
 *
 * @details $C = \alpha \cdot A \cdot B^{T} + \alpha \cdot B \cdot A^{T}
 * + \beta \cdot C$,
 *
 * or
 *
 * $C = \alpha \cdot A^{T} \cdot B + \alpha \cdot B^{T} \cdot A + \beta \cdot C$
 *
 * @param[in]       Order   The dimension, in which the elements are continuous
 * in memory. When the elements within a row are continuous in memory, then
 * CblasRowMajor should be set, and vice versa.
 *
 * @param[in]       Uplo    Specify the triangular part of C to be used in
 * computation (upper triangular part or lower triangular part).
 *
 * @param[in]       Trans   Transpose flag for matrix A.
 * When CblasNoTrans is set,
 * $C = \alpha \cdot A \cdot B^{T} + \alpha \cdot B \cdot A^{T} + \beta \cdot C$
 * When CblasConjTrans is set,
 * $C = \alpha \cdot A^{T} \cdot B + \alpha \cdot B^{T} \cdot A + \beta \cdot C$
 *
 * @param[in]       N       The order of matrix C. It must be at least 0. C is a
 * square matrix.
 *
 * @param[in]       K       Number of columns in $op(A)$. It must be at least 0.
 *
 * @param[in]       alpha   Scale, single complex precision.
 * @param[in]       A       Input matrix A, single complex precision.
 * @param[in]       lda     The leading dimension of matrix A. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 * @param[in]       B       Input matrix B, single complex precision.
 * @param[in]       ldb     The leading dimension of matrix B. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 * @param[in]       beta    Scale for the matrix C, single complex precision.
 * @param[in,out]   C       Result matrix, single complex precision.
 * @param[in]       ldc     The leading dimension of matrix C. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 */
void
cblas_csyr2k(
        const enum CBLAS_ORDER      Order,
        const enum CBLAS_UPLO       Uplo,
        const enum CBLAS_TRANSPOSE  Trans,
        const int                   N,
        const int                   K,
        const void                  *alpha,
        const void                  *A,
        const int                   lda,
        const void                  *B,
        const int                   ldb,
        const void                  *beta,
        void                        *C,
        const int                   ldc
        );


/**
 * @brief Matrix-matrix product with one triangular matrix, single complex
 * precision.
 *
 * @details $B = \alpha \cdot op(A) \cdot B$
 *
 * or
 *
 * $B = \alpha \cdot B \cdot op(A)$
 *
 * @param[in]       Order   The dimension, in which the elements are continuous
 * in memory. When the elements within a row are continuous in memory, then
 * CblasRowMajor should be set, and vice versa.
 *
 * @param[in]       Side    Specify the side of $op(A)$ relative to B.
 * @param[in]       Uplo    Specify whether the matrix A is upper triangular or
 * lower triangular.
 *
 * @param[in]       TransA  Transpose flag for matrix A.
 * When CblasNoTrans is set, $op(A) = A$. When CblasTrans is set,
 * $op(A) = A^{T}$. When CblasConjTrans is set, $op(A) = A^{*}$
 *
 * @param[in]       Diag    Specifies whether matrix A is unit triangular.
 *
 * @param[in]       M       The number of rows of matrix B. It must be at least
 * zero.
 *
 * @param[in]       N       The number of column of matrix B. It must be at
 * least zero.
 *
 * @param[in]       alpha   Scale, single complex precision.
 * @param[in]       A       Input matrix A, single complex precision.
 * @param[in]       lda     The leading dimension of matrix A. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 * @param[in,out]   B       Input and result matrix B, single complex precision.
 * @param[in]       ldb     The leading dimension of matrix B. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 */
void
cblas_ctrmm(
        const enum CBLAS_ORDER      Order,
        const enum CBLAS_SIDE       Side,
        const enum CBLAS_UPLO       Uplo,
        const enum CBLAS_TRANSPOSE  TransA,
        const enum CBLAS_DIAG       Diag,
        const int                   M,
        const int                   N,
        const void                  *alpha,
        const void                  *A,
        const int                   lda,
        void                        *B,
        const int                   ldb
        );


/**
 * @brief This function is used to solve the X in the following equation,
 * single complex precision.
 *
 * @details $op(A) \cdot X = \alpha \cdot B$
 *
 * or
 *
 * $X \cdot op(A) = \alpha \cdot B$
 *
 * @param[in]       Order   The dimension, in which the elements are continuous
 * in memory. When the elements within a row are continuous in memory, then
 * CblasRowMajor should be set, and vice versa.
 *
 * @param[in]       Side    Specify the side of $op(A)$ relative to X.
 * @param[in]       Uplo    Specify whether the matrix A is upper triangular or
 * lower triangular.
 *
 * @param[in]       TransA  Transpose flag for matrix A.
 * When CblasNoTrans is set, $op(A) = A$. When CblasTrans is set,
 * $op(A) = A^{T}$. When CblasConjTrans is set, $op(A) = A^{*}$
 *
 * @param[in]       Diag    Specifies whether matrix A is unit triangular.
 *
 * @param[in]       M       The number of rows of matrix B. It must be at least
 * zero.
 *
 * @param[in]       N       The number of column of matrix B. It must be at
 * least zero.
 *
 * @param[in]       alpha   Scale, single complex precision.
 * @param[in]       A       Input matrix A, single complex precision.
 * @param[in]       lda     The leading dimension of matrix A. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 * @param[in,out]   B       Input and result matrix B, single complex precision.
 * @param[in]       ldb     The leading dimension of matrix B. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 */
void
cblas_ctrsm(
        const enum CBLAS_ORDER      Order,
        const enum CBLAS_SIDE       Side,
        const enum CBLAS_UPLO       Uplo,
        const enum CBLAS_TRANSPOSE  TransA,
        const enum CBLAS_DIAG       Diag,
        const int                   M,
        const int                   N,
        const void                  *alpha,
        const void                  *A,
        const int                   lda,
        void                        *B,
        const int                   ldb
        );


/**
 * @brief General Matrix-Matrix multiplication, double complex precision.
 *
 * @details $C = \alpha \cdot op(A) \cdot op(B) + \beta \cdot C$, where
 * $op(X) = X$ or $X^{T}$.
 *
 * @param[in]       Order   The dimension, in which the elements are continuous
 * in memory. When the elements within a row are continuous in memory, then
 * CblasRowMajor should be set, and vice versa. It is used to describe the
 * memory layout of the input matrix, which means the transpose parameters
 * (TransA and TransB) has nothing to do with the major order.
 *
 * @param[in]       TransA  Transpose flag for matrix A. When CblasNoTrans is
 * set, $op(A) = A$. When CBlasTrans is set, $op(A) = A^{T}$. When
 * CBlasConjTrans is set, $op(A) = A^{*}$, the conjugating transpose.
 *
 * @param[in]       TransB  Transpose flag for matrix B. When CblasNoTrans is
 * set, $op(B) = B$. When CBlasTrans is set, $op(B) = B^{T}$. When
 * CBlasConjTrans is set, $op(B) = B^{*}$, the conjugating transpose.
 * @param[in]       M       Number of rows in $op(A)$ and matrix C. It must be
 * at least 0.
 *
 * @param[in]       N       Number of columns in $op(B)$ and matrix C. It must
 * be at least 0.
 *
 * @param[in]       K       Number of columns in $op(A)$, and the number of rows
 * in $op(B)$. It must be at least 0.
 *
 * @param[in]       alpha   Scale for the first matrix, double complex
 * precision. To be noticed is that, this parameter is a pointer pointing to a
 * double complex number, unlike in cblas_sgemm and cblas_dgemm.
 *
 * @param[in]       A       Input matrix A, double complex precision.
 * @param[in]       lda     The leading dimension of matrix A. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 * @param[in]       B       Input matrix B, double complex precision.
 * @param[in]       ldb     The leading dimension of matrix B. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 * @param[in]       beta    Scale for the matrix C, double complex precision. To
 * be noticed is that, this parameter is a pointer pointing to a double complex
 * number, unlike in cblas_sgemm and cblas_dgemm.
 *
 * @param[in,out]   C       Result matrix, double complex precision.
 * @param[in]       ldc     The leading dimension of matrix C. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 */
void
cblas_zgemm(
        const enum CBLAS_ORDER      Order,
        const enum CBLAS_TRANSPOSE  TransA,
        const enum CBLAS_TRANSPOSE  TransB,
        const int                   M,
        const int                   N,
        const int                   K,
        const void                  *alpha,
        const void                  *A,
        const int                   lda,
        const void                  *B,
        const int                   ldb,
        const void                  *beta,
        void                        *C,
        const int                   ldc
        );


/**
 * @brief Symmetric Matrix-Matrix multiplication, double complex precision.
 *
 * @details $C = \alpha \cdot op(A) \cdot op(B) + \beta \cdot C$,
 *
 * or
 *
 * $C = \alpha \cdot op(B) \cdot op(A) + \beta \cdot C$,
 *
 * where $op(X) = X$ or $X^{T}$.
 *
 * @param[in]       Order   The dimension, in which the elements are continuous
 * in memory. When the elements within a row are continuous in memory, then
 * CblasRowMajor should be set, and vice versa.
 *
 * @param[in]       Side    Specify the side of $op(A)$ relative to $op(B)$
 * when computing.
 *
 * @param[in]       Uplo    Specify the triangular part to be used in
 * computation (upper triangular part or lower triangular part).
 *
 * @param[in]       M       Number of rows in $op(A)$ and matrix C. It must be
 * at least 0.
 *
 * @param[in]       N       Number of columns in $op(B)$ and matrix C. It must
 * be at least 0.
 *
 * @param[in]       K       Number of columns in $op(A)$, and the number of rows
 * in $op(B)$. It must be at least 0.
 *
 * @param[in]       alpha   Scale for the first matrix, double complex
 * precision. To be noticed is that, this parameter is a pointer pointing to a
 * double complex number, unlike in cblas_sgemm and cblas_dgemm.
 *
 * @param[in]       A       Input matrix A, double complex precision.
 * @param[in]       lda     The leading dimension of matrix A. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 * @param[in]       B       Input matrix B, double complex precision.
 * @param[in]       ldb     The leading dimension of matrix B. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 * @param[in]       beta    Scale for the matrix C, double complex precision. To
 * be noticed is that, this parameter is a pointer pointing to a double complex
 * number, unlike in cblas_sgemm and cblas_dgemm.
 *
 * @param[in,out]   C       Result matrix, double complex precision.
 * @param[in]       ldc     The leading dimension of matrix C. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 */
void
cblas_zsymm(
        const enum CBLAS_ORDER  Order,
        const enum CBLAS_SIDE   Side,
        const enum CBLAS_UPLO   Uplo,
        const int               M,
        const int               N,
        const void              *alpha,
        const void              *A,
        const int               lda,
        const void              *B,
        const int               ldb,
        const void              *beta,
        void                    *C,
        const int               ldc
        );


/**
 * @brief Perform a rank-k matrix-matrix operation for a symmetric matrix with
 * a general matrix. Double complex precision.
 *
 * @details $C = \alpha \cdot A \cdot A^{T} + \beta \cdot C$,
 *
 * or
 *
 * $C = \alpha \cdot A^{T} \cdot A + \beta \cdot C$,
 *
 * @param[in]       Order   The dimension, in which the elements are continuous
 * in memory. When the elements within a row are continuous in memory, then
 * CblasRowMajor should be set, and vice versa.
 *
 * @param[in]       Uplo    Specify the triangular part of C to be used in
 * computation (upper triangular part or lower triangular part).
 *
 * @param[in]       Trans   Transpose flag for matrix A. When CblasNoTrans is
 * set, $C = \alpha \cdot A \cdot A^{T} + \beta \cdot C$. When CblasTrans or
 * CblasConjTrans is set $C = \alpha \cdot A^{T} \cdot A + \beta \codt C$.
 *
 * @param[in]       N       The order of matrix C. It must be at least 0. C is a
 * square matrix.
 *
 * @param[in]       K       Number of columns in $op(A)$. It must be at least 0.
 *
 * @param[in]       alpha   Scale for matrix A, double complex precision.
 * @param[in]       A       Input matrix A, double complex precision.
 * @param[in]       lda     The leading dimension of matrix A. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 * @param[in]       beta    Scale for the matrix C, double complex precision.
 * @param[in,out]   C       Result matrix, double complex precision.
 * @param[in]       ldc     The leading dimension of matrix C. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 */
void
cblas_zsyrk(
        const enum CBLAS_ORDER      Order,
        const enum CBLAS_UPLO       Uplo,
        const enum CBLAS_TRANSPOSE  Trans,
        const int                   N,
        const int                   K,
        const void                  *alpha,
        const void                  *A,
        const int                   lda,
        const void                  *beta,
        void                        *C,
        const int                   ldc
        );


/**
 * @brief Perform a rank-2 matrix-matrix operation for a symmetric matrix with
 * two general matrix. Double complex precision.
 *
 * @details $C = \alpha \cdot A \cdot B^{T} + \alpha \cdot B \cdot A^{T}
 * + \beta \cdot C$,
 *
 * or
 *
 * $C = \alpha \cdot A^{T} \cdot B + \alpha \cdot B^{T} \cdot A + \beta \cdot C$
 *
 * @param[in]       Order   The dimension, in which the elements are continuous
 * in memory. When the elements within a row are continuous in memory, then
 * CblasRowMajor should be set, and vice versa.
 *
 * @param[in]       Uplo    Specify the triangular part of C to be used in
 * computation (upper triangular part or lower triangular part).
 *
 * @param[in]       Trans   Transpose flag for matrix A.
 * When CblasNoTrans is set,
 * $C = \alpha \cdot A \cdot B^{T} + \alpha \cdot B \cdot A^{T} + \beta \cdot C$
 * When CblasConjTrans is set,
 * $C = \alpha \cdot A^{T} \cdot B + \alpha \cdot B^{T} \cdot A + \beta \cdot C$
 *
 * @param[in]       N       The order of matrix C. It must be at least 0. C is a
 * square matrix.
 *
 * @param[in]       K       Number of columns in $op(A)$. It must be at least 0.
 *
 * @param[in]       alpha   Scale, double complex precision.
 * @param[in]       A       Input matrix A, double complex precision.
 * @param[in]       lda     The leading dimension of matrix A. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 * @param[in]       B       Input matrix B, double complex precision.
 * @param[in]       ldb     The leading dimension of matrix B. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 * @param[in]       beta    Scale for the matrix C, double complex precision.
 * @param[in,out]   C       Result matrix, double complex precision.
 * @param[in]       ldc     The leading dimension of matrix C. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 */
void
cblas_zsyr2k(
        const enum CBLAS_ORDER      Order,
        const enum CBLAS_UPLO       Uplo,
        const enum CBLAS_TRANSPOSE  Trans,
        const int                   N,
        const int                   K,
        const void                  *alpha,
        const void                  *A,
        const int                   lda,
        const void                  *B,
        const int                   ldb,
        const void                  *beta,
        void                        *C,
        const int                   ldc
        );


/**
 * @brief Matrix-matrix product with one triangular matrix, double complex
 * precision.
 *
 * @details $B = \alpha \cdot op(A) \cdot B$
 *
 * or
 *
 * $B = \alpha \cdot B \cdot op(A)$
 *
 * @param[in]       Order   The dimension, in which the elements are continuous
 * in memory. When the elements within a row are continuous in memory, then
 * CblasRowMajor should be set, and vice versa.
 *
 * @param[in]       Side    Specify the side of $op(A)$ relative to B.
 * @param[in]       Uplo    Specify whether the matrix A is upper triangular or
 * lower triangular.
 *
 * @param[in]       TransA  Transpose flag for matrix A.
 * When CblasNoTrans is set, $op(A) = A$. When CblasTrans is set,
 * $op(A) = A^{T}$. When CblasConjTrans is set, $op(A) = A^{*}$
 *
 * @param[in]       Diag    Specifies whether matrix A is unit triangular.
 *
 * @param[in]       M       The number of rows of matrix B. It must be at least
 * zero.
 *
 * @param[in]       N       The number of column of matrix B. It must be at
 * least zero.
 *
 * @param[in]       alpha   Scale, double complex precision.
 * @param[in]       A       Input matrix A, double complex precision.
 * @param[in]       lda     The leading dimension of matrix A. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 * @param[in,out]   B       Input and result matrix B, double complex precision.
 * @param[in]       ldb     The leading dimension of matrix B. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 */
void
cblas_ztrmm(
        const enum CBLAS_ORDER      Order,
        const enum CBLAS_SIDE       Side,
        const enum CBLAS_UPLO       Uplo,
        const enum CBLAS_TRANSPOSE  TransA,
        const enum CBLAS_DIAG       Diag,
        const int                   M,
        const int                   N,
        const void                  *alpha,
        const void                  *A,
        const int                   lda,
        void                        *B,
        const int                   ldb
        );


/**
 * @brief This function is used to solve the X in the following equation,
 * double complex precision.
 *
 * @details $op(A) \cdot X = \alpha \cdot B$
 *
 * or
 *
 * $X \cdot op(A) = \alpha \cdot B$
 *
 * @param[in]       Order   The dimension, in which the elements are continuous
 * in memory. When the elements within a row are continuous in memory, then
 * CblasRowMajor should be set, and vice versa.
 *
 * @param[in]       Side    Specify the side of $op(A)$ relative to X.
 * @param[in]       Uplo    Specify whether the matrix A is upper triangular or
 * lower triangular.
 *
 * @param[in]       TransA  Transpose flag for matrix A.
 * When CblasNoTrans is set, $op(A) = A$. When CblasTrans is set,
 * $op(A) = A^{T}$. When CblasConjTrans is set, $op(A) = A^{*}$
 *
 * @param[in]       Diag    Specifies whether matrix A is unit triangular.
 *
 * @param[in]       M       The number of rows of matrix B. It must be at least
 * zero.
 *
 * @param[in]       N       The number of column of matrix B. It must be at
 * least zero.
 *
 * @param[in]       alpha   Scale, double complex precision.
 * @param[in]       A       Input matrix A, double complex precision.
 * @param[in]       lda     The leading dimension of matrix A. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 * @param[in,out]   B       Input and result matrix B, double complex precision.
 * @param[in]       ldb     The leading dimension of matrix B. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 */
void
cblas_ztrsm(
        const enum CBLAS_ORDER      Order,
        const enum CBLAS_SIDE       Side,
        const enum CBLAS_UPLO       Uplo,
        const enum CBLAS_TRANSPOSE  TransA,
        const enum CBLAS_DIAG       Diag,
        const int                   M,
        const int                   N,
        const void                  *alpha,
        const void                  *A,
        const int                   lda,
        void                        *B,
        const int                   ldb
        );


/*
 * Routines with prefixes C and Z only
 */


/**
 * @brief This function computes scalar-matrix-matrix product using a Hermitian
 * matrix A and a general matrix B and add the result to a scalar-matrix product
 * using a general matrix C. Single complex precision.
 *
 * @details $C = \alhpa \cdot A \cdot B + \beta \cdot C$
 *
 * or
 *
 * $C = \alhpa \cdot B \cdot A + \beta \cdot C$
 *
 * @param[in]       Order   The dimension, in which the elements are continuous
 * in memory. When the elements within a row are continuous in memory, then
 * CblasRowMajor should be set, and vice versa.
 *
 * @param[in]       Side    Specify the side of A relative to B.
 * @param[in]       Uplo    Specify which triangular part of matrix A should be
 * used. When CblasUpper is set, the upper part of Hermitian matrix A is used.
 * When CblasLower is set, the lower part of Hermitian matrix A is used.
 *
 * @param[in]       M       The number of rows of matrix C. It must be at least
 * zero.
 *
 * @param[in]       N       The number of column of matrix C. It must be at
 * least zero.
 *
 * @param[in]       alpha   Scale, single complex precision.
 * @param[in]       A       Hermitian matrix A, single complex precision.
 * @param[in]       lda     The leading dimension of matrix A. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 * @param[in]       B       Input matrix B, single complex precision.
 * @param[in]       ldb     The leading dimension of matrix B. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 * @param[in]       beta    Scale for the matrix C, single complex precision.
 * @param[in,out]   C       Result matrix, single complex precision.
 * @param[in]       ldc     The leading dimension of matrix C. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 */
void
cblas_chemm(
        const enum CBLAS_ORDER  Order,
        const enum CBLAS_SIDE   Side,
        const enum CBLAS_UPLO   Uplo,
        const int               M,
        const int               N,
        const void              *alpha,
        const void              *A,
        const int               lda,
        const void              *B,
        const int               ldb,
        const void              *beta,
        void                    *C,
        const int               ldc
        );


/**
 * @brief Perform a rank-k matrix-matrix operation using a general matrix A with
 * a Hermitian matrix C. Single complex precision.
 *
 * @details $C = \alpha \cdot A \cdot A^{*} + \beta \cdot C$,
 *
 * or
 *
 * $C = \alpha \cdot A^{*} \cdot A + \beta \cdot C$,
 *
 * @param[in]       Order   The dimension, in which the elements are continuous
 * in memory. When the elements within a row are continuous in memory, then
 * CblasRowMajor should be set, and vice versa.
 *
 * @param[in]       Uplo    Specify the triangular part of C to be used in
 * computation (upper triangular part or lower triangular part).
 *
 * @param[in]       Trans   Transpose flag for matrix A. When CblasNoTrans is
 * set, $C = \alpha \cdot A \cdot A^{*} + \beta \cdot C$. When CblasTrans or
 * CblasConjTrans is set $C = \alpha \cdot A^{*} \cdot A + \beta \codt C$.
 *
 * @param[in]       N       The order of matrix C. It must be at least 0. C is a
 * square matrix.
 *
 * @param[in]       K       Number of columns in $op(A)$. It must be at least 0.
 *
 * @param[in]       alpha   Scale for matrix A, single complex precision.
 * @param[in]       A       Input matrix A, single complex precision.
 * @param[in]       lda     The leading dimension of matrix A. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 * @param[in]       beta    Scale for the matrix C, single complex precision.
 * @param[in,out]   C       Result Hermitian matrix, single complex precision.
 * @param[in]       ldc     The leading dimension of matrix C. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 */
void
cblas_cherk(
        const enum CBLAS_ORDER      Order,
        const enum CBLAS_UPLO       Uplo,
        const enum CBLAS_TRANSPOSE  Trans,
        const int                   N,
        const int                   K,
        const float                 alpha,
        const void                  *A,
        const int                   lda,
        const float                 beta,
        void                        *C,
        const int                   ldc
        );


/**
 * @brief Perform a rank-2 matrix-matrix operation using general matrices A and
 * B and a Hermitian matrix C. Double complex precision.
 *
 * @details $C = \alpha \cdot A \cdot B^{*} + \bar{\alpha} \cdot B \cdot A^{*}
 * + \beta \cdot C$,
 *
 * or
 *
 * $C = \alpha \cdot A^{*} \cdot B + \bar{\alpha} \cdot B^{*} \cdot A
 * + \beta \cdot C$
 *
 * @param[in]       Order   The dimension, in which the elements are continuous
 * in memory. When the elements within a row are continuous in memory, then
 * CblasRowMajor should be set, and vice versa.
 *
 * @param[in]       Uplo    Specify the triangular part of C to be used in
 * computation (upper triangular part or lower triangular part).
 *
 * @param[in]       Trans   Transpose flag for matrix A.
 * When CblasNoTrans is set,
 * $C = \alpha \cdot A \cdot B^{*} + \alpha \cdot B \cdot A^{*} + \beta \cdot C$
 * When CblasConjTrans is set,
 * $C = \alpha \cdot A^{*} \cdot B + \alpha \cdot B^{*} \cdot A + \beta \cdot C$
 *
 * @param[in]       N       The order of matrix C. It must be at least 0. C is a
 * square matrix.
 *
 * @param[in]       K       Number of columns in $op(A)$. It must be at least 0.
 *
 * @param[in]       alpha   Scale, single complex precision.
 * @param[in]       A       Input matrix A, single complex precision.
 * @param[in]       lda     The leading dimension of matrix A. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 * @param[in]       B       Input matrix B, single complex precision.
 * @param[in]       ldb     The leading dimension of matrix B. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 * @param[in]       beta    Scale for the matrix C, single complex precision.
 * @param[in,out]   C       Result matrix, single complex precision.
 * @param[in]       ldc     The leading dimension of matrix C. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 */
void
cblas_cher2k(
        const enum CBLAS_ORDER      Order,
        const enum CBLAS_UPLO       Uplo,
        const enum CBLAS_TRANSPOSE  Trans,
        const int                   N,
        const int                   K,
        const void                  *alpha,
        const void                  *A,
        const int                   lda,
        const void                  *B,
        const int                   ldb,
        const float                 beta,
        void                        *C,
        const int                   ldc
        );


/**
 * @brief This function computes scalar-matrix-matrix product using a Hermitian
 * matrix A and a general matrix B and add the result to a scalar-matrix product
 * using a general matrix C. Single complex precision.
 *
 * @details $C = \alhpa \cdot A \cdot B + \beta \cdot C$
 *
 * or
 *
 * $C = \alhpa \cdot B \cdot A + \beta \cdot C$
 *
 * @param[in]       Order   The dimension, in which the elements are continuous
 * in memory. When the elements within a row are continuous in memory, then
 * CblasRowMajor should be set, and vice versa.
 *
 * @param[in]       Side    Specify the side of A relative to B.
 * @param[in]       Uplo    Specify which triangular part of matrix A should be
 * used. When CblasUpper is set, the upper part of Hermitian matrix A is used.
 * When CblasLower is set, the lower part of Hermitian matrix A is used.
 *
 * @param[in]       M       The number of rows of matrix C. It must be at least
 * zero.
 * least zero.
 *
 * @param[in]       alpha   Scale, double complex precision.
 * @param[in]       A       Hermitian matrix A, double complex precision.
 * @param[in]       lda     The leading dimension of matrix A. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 * @param[in]       B       Input matrix B, double complex precision.
 * @param[in]       ldb     The leading dimension of matrix B. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 * @param[in]       beta    Scale for the matrix C, double complex precision.
 * @param[in,out]   C       Result matrix, double complex precision.
 * @param[in]       ldc     The leading dimension of matrix C. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 */
void
cblas_zhemm(
        const enum CBLAS_ORDER  Order,
        const enum CBLAS_SIDE   Side,
        const enum CBLAS_UPLO   Uplo,
        const int               M,
        const int               N,
        const void              *alpha,
        const void              *A,
        const int               lda,
        const void              *B,
        const int               ldb,
        const void              *beta,
        void                    *C,
        const int               ldc
        );


/**
 * @brief Perform a rank-k matrix-matrix operation using a general matrix A with
 * a Hermitian matrix C. Double complex precision.
 *
 * @details $C = \alpha \cdot A \cdot A^{*} + \beta \cdot C$,
 *
 * or
 *
 * $C = \alpha \cdot A^{*} \cdot A + \beta \cdot C$,
 *
 * @param[in]       Order   The dimension, in which the elements are continuous
 * in memory. When the elements within a row are continuous in memory, then
 * CblasRowMajor should be set, and vice versa.
 *
 * @param[in]       Uplo    Specify the triangular part of C to be used in
 * computation (upper triangular part or lower triangular part).
 *
 * @param[in]       Trans   Transpose flag for matrix A. When CblasNoTrans is
 * set, $C = \alpha \cdot A \cdot A^{*} + \beta \cdot C$. When CblasTrans or
 * CblasConjTrans is set $C = \alpha \cdot A^{*} \cdot A + \beta \codt C$.
 *
 * @param[in]       N       The order of matrix C. It must be at least 0. C is a
 * square matrix.
 *
 * @param[in]       K       Number of columns in $op(A)$. It must be at least 0.
 *
 * @param[in]       alpha   Scale for matrix A, double complex precision.
 * @param[in]       A       Input matrix A, double complex precision.
 * @param[in]       lda     The leading dimension of matrix A. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 * @param[in]       beta    Scale for the matrix C, double complex precision.
 * @param[in,out]   C       Result Hermitian matrix, double complex precision.
 * @param[in]       ldc     The leading dimension of matrix C. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 */
void
cblas_zherk(
        const enum CBLAS_ORDER      Order,
        const enum CBLAS_UPLO       Uplo,
        const enum CBLAS_TRANSPOSE  Trans,
        const int                   N,
        const int                   K,
        const double                alpha,
        const void                  *A,
        const int                   lda,
        const double                beta,
        void                        *C,
        const int                   ldc
        );


/**
 * @brief Perform a rank-2 matrix-matrix operation using general matrices A and
 * B and a Hermitian matrix C. Double complex precision.
 *
 * @details $C = \alpha \cdot A \cdot B^{*} + \bar{\alpha} \cdot B \cdot A^{*}
 * + \beta \cdot C$,
 *
 * or
 *
 * $C = \alpha \cdot A^{*} \cdot B + \bar{\alpha} \cdot B^{*} \cdot A
 * + \beta \cdot C$
 *
 * @param[in]       Order   The dimension, in which the elements are continuous
 * in memory. When the elements within a row are continuous in memory, then
 * CblasRowMajor should be set, and vice versa.
 *
 * @param[in]       Uplo    Specify the triangular part of C to be used in
 * computation (upper triangular part or lower triangular part).
 *
 * @param[in]       Trans   Transpose flag for matrix A.
 * When CblasNoTrans is set,
 * $C = \alpha \cdot A \cdot B^{*} + \alpha \cdot B \cdot A^{*} + \beta \cdot C$
 * When CblasConjTrans is set,
 * $C = \alpha \cdot A^{*} \cdot B + \alpha \cdot B^{*} \cdot A + \beta \cdot C$
 *
 * @param[in]       N       The order of matrix C. It must be at least 0. C is a
 * square matrix.
 *
 * @param[in]       K       Number of columns in $op(A)$. It must be at least 0.
 *
 * @param[in]       alpha   Scale, double complex precision.
 * @param[in]       A       Input matrix A, double complex precision.
 * @param[in]       lda     The leading dimension of matrix A. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 * @param[in]       B       Input matrix B, double complex precision.
 * @param[in]       ldb     The leading dimension of matrix B. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 * @param[in]       beta    Scale for the matrix C, double complex precision.
 * @param[in,out]   C       Result matrix, double complex precision.
 * @param[in]       ldc     The leading dimension of matrix C. It should be
 * equal to or larger than the length of the major order dimension described by
 * parameter Order.
 *
 */
void
cblas_zher2k(
        const enum CBLAS_ORDER      Order,
        const enum CBLAS_UPLO       Uplo,
        const enum CBLAS_TRANSPOSE  Trans,
        const int                   N,
        const int                   K,
        const void                  *alpha,
        const void                  *A,
        const int                   lda,
        const void                  *B,
        const int                   ldb,
        const double                beta,
        void                        *C,
        const int                   ldc
        );


/**
 * @brief An error handler.
 *
 * @param[in]   p       Position of the invalid parameter in the parameter list
 * of the calling routine.
 *
 * @param[in]   rout    Routine name.
 *
 * @param[in]   form    Format.
 *
 */
void
cblas_xerbla(
        int         p,
        const char  *rout,
        const char  *form,
        ...
        );

#ifdef __cplusplus
}
#endif
#endif
