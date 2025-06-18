cmake_minimum_required(VERSION 3.29)
project(SDA_Lab1 C)

set(CMAKE_C_STANDARD 11)

add_executable(Ex2 main.c
        functions.c)
add_executable(Ex2.1 EX2.c)

add_compile_options("-Wall" "-Wextra" "-Wpedantic")
