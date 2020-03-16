
include_directories(
        ../external/httplib
        ../external/catch2
)

add_executable(
        TestAll
        test.cpp
        ../external/httplib/httplib.h
        ../external/catch2/catch.hpp
)