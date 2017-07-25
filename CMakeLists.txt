cmake_minimum_required(VERSION 3.6)
project(COREWAR)

set(CMAKE_C_STANDARD 99)

file(GLOB_RECURSE MY_SRC ${PROJECT_SOURCE_DIR}/push_swap/*.c ${PROJECT_SOURCE_DIR}/push_swap/*.h)

add_executable(COREWAR ${MY_SRC})