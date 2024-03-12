#include "matrix.hpp"
#include <iostream>



int main() {

    math::Matrix A(2, 2);
    for (int i = 0; i < A.rows(); ++i) 
    {
        for (int j = 0; j < A.cols(); ++j) 
        {
        A(i, j) = 1.0 / (i + j + 1);
        }
    }

    for (int i = 0; i < A.rows(); ++i) 
    {
        for (int j = 0; j < A.cols(); ++j) 
        {
        std::cout << A.at(i, j) <<',';
        }
        std::cout << '\n';
    }

}