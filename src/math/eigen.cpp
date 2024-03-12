#pragma once
#include "eigen.hpp"
#include "matrix.hpp"
#include "lapack.hpp"
#include <cassert>
#include <iostream>

namespace math {

MatrixAndVector realSymmetricEigenstate(Matrix matrix) {
  assert(matrix.rows() == matrix.cols() &&
         "RealSymmetric only works for square matrix");

  MatrixAndVector result(matrix.rows());

  // Data required by dsyev. See documentation for description of each option:
  // http://www.netlib.org/lapack/explore-html/index.html
  char jobz{'V'};
  char uplo{'U'};
  int dimension = static_cast<int>(matrix.rows()); // LAPACK expects an int
  int lwork = 6 * dimension;
  std::vector<double> work(static_cast<std::size_t>(lwork));
  int info;

  // calculate eigenvalues using the DSYEV lapack subroutine
  // on INPUT, 'matrix' is the matrix to invert. After dsyev_ exits, 'matrix'
  // will hold the eigenvectors, and 'result.vector' will hold the eigenvalues
  dsyev_(&jobz, &uplo, &dimension, matrix.data(), &dimension,
         result.vector.data(), work.data(), &lwork, &info);

  // move the data from original matrix into matrix that lives in
  // 'MatrixAndVector' - which we return
  result.matrix = std::move(matrix);

  // check for errors
  if (info != 0) {
    std::cout << "DSYEV returned error code: " << info << '\n';
  }

  return result; // nb: named return-value optimisation (NRVO) is used here
}

MatrixAndVector realGeneralisedSymmetricDefiniteEigenstate(Matrix matrixa, Matrix matrixb) {
    MatrixAndVector result(matrix.rows());
    return result;
}


}
