cmake_minimum_required(VERSION 2.8)

project(pthread_create)

find_package(Threads REQUIRED)

add_executable(${PROJECT_NAME} "main.c")

target_link_libraries(${PROJECT_NAME} -lpthread)
