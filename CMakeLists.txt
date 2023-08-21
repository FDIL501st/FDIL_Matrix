cmake_minimum_required(VERSION 3.25)
project(FDIL_Matrix)

set(CMAKE_CXX_STANDARD 23)

add_executable(FDIL_Matrix main.cpp Matrix.cpp Matrix.h MatrixSize.cpp MatrixSize.h)
