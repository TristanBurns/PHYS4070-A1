#pragma once

#include <vector>
#include <cstddef> // for std::size_t

namespace math { 

class Matrix{
private:
    std::vector<double> m_data;
    std::size_t m_rows, m_cols;

public:
    Matrix(std::size_t rows, std::size_t cols);

    std::size_t rows() const;
    std::size_t cols() const;

    double &at(std::size_t i, std::size_t j);
    double at(std::size_t i, std::size_t j) const;

    double &operator()(std::size_t i, std::size_t j);
    double operator()(std::size_t i, std::size_t j) const;

    double *data();
};

Matrix &operator+=(Matrix &a, const Matrix &b);
Matrix &operator-=(Matrix &a, const Matrix &b);
Matrix operator+(const Matrix &a, const Matrix &b);
Matrix operator-(const Matrix &a, const Matrix &b);

Matrix &operator*=(Matrix &a, double x);
Matrix operator*(Matrix a, double x);
Matrix operator*(double x, Matrix a);

} // namespace math