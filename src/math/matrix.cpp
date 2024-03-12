#include "Matrix.hpp"
#include <cassert>

namespace math { 

Matrix::Matrix(std::size_t rows, std::size_t cols)
    : m_data(rows * cols), m_rows(rows), m_cols(cols) {}

std::size_t Matrix::rows() const { return m_rows; }

std::size_t Matrix::cols() const { return m_cols; }

double &Matrix::at(std::size_t i, std::size_t j) {
  assert(i < m_rows && j < m_cols);
  return m_data[i * m_cols + j];
}

double Matrix::at(std::size_t i, std::size_t j) const {
  assert(i < m_rows && j < m_cols);
  return m_data[i * m_cols + j];
}

double &Matrix::operator()(std::size_t i, std::size_t j) { return at(i, j); }

double Matrix::operator()(std::size_t i, std::size_t j) const {
  return at(i, j);
}

double *Matrix::data() { return m_data.data(); }

Matrix &operator+=(Matrix &a, const Matrix &b) {
  assert(a.rows() == b.rows() && a.cols() == b.cols());
  for (std::size_t i = 0; i < a.rows(); ++i) {
    for (std::size_t j = 0; j < a.cols(); ++j) {
      a(i, j) += b(i, j);
    }
  }
  return a;
}

Matrix &operator-=(Matrix &a, const Matrix &b) {
  assert(a.rows() == b.rows() && a.cols() == b.cols());
  for (std::size_t i = 0; i < a.rows(); ++i) {
    for (std::size_t j = 0; j < a.cols(); ++j) {
      a(i, j) -= b(i, j);
    }
  }
  return a;
}

Matrix operator+(const Matrix &a, const Matrix &b) {
  Matrix result = a;
  result += b;
  return result;
}

Matrix operator-(const Matrix &a, const Matrix &b) {
  Matrix result = a;
  result -= b;
  return result;
}

Matrix &operator*=(Matrix &a, double x) {
  for (std::size_t i = 0; i < a.rows(); ++i) {
    for (std::size_t j = 0; j < a.cols(); ++j) {
      a(i, j) *= x;
    }
  }
  return a;
}

Matrix operator*(Matrix a, double x) {
  a *= x;
  return a;
}

Matrix operator*(double x, Matrix a) {
  a *= x;
  return a;
}

} // namespace math
