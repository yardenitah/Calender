cmake_minimum_required(VERSION 3.23)
project(ex1)

set(CMAKE_CXX_STANDARD 14)

add_executable(ex1 main.cpp MyDate.cpp MyDate.h Calander.cpp Calander.h cmake-build-debug/HHR.cpp cmake-build-debug/HHR.h BST.cpp BST.h)
