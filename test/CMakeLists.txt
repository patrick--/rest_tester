
include_directories(
        ../external/httplib
        ../external/catch2
        ../external/json11
        ../src
)

add_executable(
        TestAll
        test.cpp
        ../external/httplib/httplib.h
        ../external/catch2/catch.hpp
        ../external/json11/json11.cpp ../external/json11/json11.hpp
        ../src/handlers.cpp ../src/handlers.h
        ../src/http_utility.cpp ../src/http_utility.cpp
        ../src/json_utility.h
        ../src/server_manager.cpp ../src/server_manager.h
)

target_link_libraries(TestAll pthread)