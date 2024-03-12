extern "C" {

    // LAPACK function dsyev_ computes all eigenvalues and, optionally,
    // eigenvectors of a real symmetric matrix A.
    //
    // Parameters:
    // JOBZ    (input) CHARACTER*1
    //         = 'N': Compute eigenvalues only;
    //         = 'V': Compute eigenvalues and eigenvectors.
    //
    // UPLO    (input) CHARACTER*1
    //         = 'U': Upper triangle of A is stored;
    //         = 'L': Lower triangle of A is stored.
    //
    // N       (input) INTEGER
    //         The order of the matrix A. N >= 0.
    //
    // A       (input/output) DOUBLE PRECISION array, dimension (LDA, N)
    //         On entry, the symmetric matrix A. If UPLO = 'U', the leading
    //         N-by-N upper triangular part of A contains the upper
    //         triangular part of the matrix A. If UPLO = 'L', the leading
    //         N-by-N lower triangular part of A contains the lower
    //         triangular part of the matrix A.
    //         On exit, if JOBZ = 'V', then if INFO = 0, A contains the
    //         orthonormal eigenvectors of the matrix A.
    //         If JOBZ = 'N', then on exit the lower triangle (if UPLO='L') or
    //         the upper triangle (if UPLO='U') of A, including the
    //         diagonal, is destroyed.
    //
    // LDA     (input) INTEGER
    //         The leading dimension of the array A. LDA >= max(1, N).
    //
    // W       (output) DOUBLE PRECISION array, dimension (N)
    //         If INFO = 0, the eigenvalues in ascending order.
    //
    // WORK    (workspace/output) DOUBLE PRECISION array, dimension (LWORK)
    //         On exit, if INFO = 0, WORK(1) returns the optimal LWORK.
    //
    // LWORK   (input) INTEGER
    //         The dimension of the array WORK. LWORK >= max(1, 3*N-1).
    //         For optimal efficiency, LWORK >= (NB+2)*N,
    //         where NB is the blocksize for DSYTRD returned by ILAENV.
    //
    // INFO    (output) INTEGER
    //         = 0: successful exit
    //         < 0: if INFO = -i, the i-th argument had an illegal value
    //         > 0: if INFO = i, the algorithm failed to converge; i
    //              off-diagonal elements of an intermediate tridiagonal
    //              form did not converge to zero.
    //
    int dsyev_(char* jobz, char* uplo, int* n, double* a, int* lda,
               double* w, double* work, int* lwork, int* info);
    
    // LAPACK function dsygv_ solves the generalized eigenvalue problem
    // for a pair of real symmetric matrices (A, B).
    // 
    // Parameters:
    // ITYPE   (input) INTEGER
    //         Specifies the problem type to be solved:
    //         = 1: A*x = (lambda)*B*x
    //         = 2: A*B*x = (lambda)*x
    //         = 3: B*A*x = (lambda)*x
    //
    // JOBZ    (input) CHARACTER*1
    //         = 'N': Compute eigenvalues only;
    //         = 'V': Compute eigenvalues and eigenvectors.
    //
    // UPLO    (input) CHARACTER*1
    //         = 'U': Upper triangles of A and B are stored;
    //         = 'L': Lower triangles of A and B are stored.
    //
    // N       (input) INTEGER
    //         The order of the matrices A and B. N >= 0.
    //
    // A       (input/output) DOUBLE PRECISION array, dimension (LDA, N)
    //         On entry, the symmetric matrix A. If UPLO = 'U', the leading
    //         N-by-N upper triangular part of A contains the upper
    //         triangular part of the matrix A. If UPLO = 'L', the leading
    //         N-by-N lower triangular part of A contains the lower
    //         triangular part of the matrix A.
    //         On exit, the contents of A are destroyed.
    //
    // LDA     (input) INTEGER
    //         The leading dimension of the array A. LDA >= max(1, N).
    //
    // B       (input/output) DOUBLE PRECISION array, dimension (LDB, N)
    //         On entry, the symmetric matrix B. If UPLO = 'U', the leading
    //         N-by-N upper triangular part of B contains the upper
    //         triangular part of the matrix B. If UPLO = 'L', the leading
    //         N-by-N lower triangular part of B contains the lower
    //         triangular part of the matrix B.
    //         On exit, if INFO <= 0, the part of B containing the matrix is
    //         overwritten by the triangular factor U or L from the Cholesky
    //         factorization B = U**T*U or B = L*L**T.
    //
    // LDB     (input) INTEGER
    //         The leading dimension of the array B. LDB >= max(1, N).
    //
    // W       (output) DOUBLE PRECISION array, dimension (N)
    //         If INFO = 0, the eigenvalues in ascending order.
    //
    // WORK    (workspace/output) DOUBLE PRECISION array, dimension (MAX(1, LWORK))
    //         On exit, if INFO = 0, WORK(1) returns the optimal LWORK.
    //
    // LWORK   (input) INTEGER
    //         The length of the array WORK. LWORK >= max(1,3*N-1).
    //         For optimal efficiency, LWORK >= (NB+2)*N,
    //         where NB is the blocksize for DSYTRD returned by ILAENV.
    //
    // INFO    (output) INTEGER
    //         = 0: successful exit
    //         < 0: if INFO = -i, the i-th argument had an illegal value
    //         > 0: if INFO = i, the algorithm failed to converge; i
    //              off-diagonal elements of an intermediate tridiagonal
    //              form did not converge to zero.
    
    int dsygv_(int* itype, char* jobz, char* uplo, int* n, double* a, int* lda,
               double* b, int* ldb, double* w, double* work, int* lwork, int* info);
  
}
