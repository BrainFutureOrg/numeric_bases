cmake_minimum_required(VERSION 3.26)
project(numeric_bases C)

set(CMAKE_C_STANDARD 11)

add_executable(numeric_bases main.c
        digit_sequence.c
        digit_sequence.h)
