cmake_minimum_required(VERSION 3.30)
project(untitled1)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled1 main.cpp
        sorting_algorithms.cpp
        sorting_algorithms.h
        searching_algorithms.cpp
        searching_algorithms.h
        array_tools.cpp
        array_tools.h)
