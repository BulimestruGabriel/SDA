cmake_minimum_required(VERSION 3.29)
project(SDA_Lab5 C)

set(CMAKE_C_STANDARD 11)


add_executable(SDA_Lab5 main.c
        functions.c)

add_compile_options("-Wall" "-Wextra" "-Wpedantic")