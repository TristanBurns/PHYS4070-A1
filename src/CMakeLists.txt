cmake_minimum_required(VERSION 3.10) # Specify the minimum version of CMake

project(PHYS4070 VERSION 1.0) # Name and version of your project

# Specify C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directory for header files
include_directories(math provided)

# Add executable target with source files
add_executable(B1 main/main.cpp math/matrix.cpp)
add_executable(B2 main/main.cpp math/matrix.cpp)
add_executable(B3 main/main.cpp math/matrix.cpp)
add_executable(B4 main/main.cpp math/matrix.cpp)