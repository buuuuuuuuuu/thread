cmake_minimum_required(VERSION 2.8)

project(unique_lock)
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -march=native -O3 -pthread" )
add_executable(${PROJECT_NAME} "main.cpp")
