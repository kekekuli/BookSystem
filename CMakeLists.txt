cmake_minimum_required(VERSION 3.21)
project(BookSystem C)

set(CMAKE_C_STANDARD 17)

add_executable(BookSystem main.c BookSystem.h BookSystem.c)
target_include_directories(
        BookSystem
        PUBLIC
        "{PROJECT_BINARY_DIR}"
)