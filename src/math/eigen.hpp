#pragma once
#include "matrix.hpp"
#include <vector>

namespace math {

// Very simple struct; stores a matrix and a vector - used to hold the matrix of
// eigenvectors, and a vector of eigenvalues
struct MatrixAndVector 
{
MatrixAndVector(std::size_t dimension)
    : matrix(dimension, dimension), vector(dimension) {}
    math::Matrix matrix;
    std::vector<double> vector;
};

// Finds eigen values and eigen vectors of real, symmetric matrix
// nb: takes by copy, since matrix will be destroyed by LAPACK
MatrixAndVector realSymmetricEigenstate(math::Matrix A);

MatrixAndVector realGeneralisedSymmetricDefiniteEigenstate(math::Matrix A, math::matrix B);

} // namespace eigen
