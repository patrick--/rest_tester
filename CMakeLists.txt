cmake_minimum_required(VERSION 3.15)
project(rest_tester)

set(CMAKE_CXX_STANDARD 14)

enable_testing()

add_subdirectory(test)
add_test(Tests TestAll) 