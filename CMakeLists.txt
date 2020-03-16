cmake_minimum_required(VERSION 3.15)
project(rest_tester)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src)

enable_testing()

add_subdirectory(test)
add_test(Tests TestAll) 