cmake_minimum_required(VERSION 3.29)
project(SDA_Lab2 C)

set(CMAKE_C_STANDARD 11)

add_executable(Lab2 main.c
        functions.c)

add_compile_options("-Wall" "-Wextra" "-Wpedantic")