cmake_minimum_required(VERSION 3.19)
project(RootFinder)

set(CMAKE_CXX_STANDARD 14)

add_executable(RootFinder main.cpp polynomial.h complex.h guessMatrix.h)