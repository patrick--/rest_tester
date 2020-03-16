

include_directories(
        ../external/httplib
        ../external/catch2
        ../external/json11
)

add_executable(
        rest_tester
        main.cpp
        handlers.cpp handlers.h
        http_utility.cpp  json_utility.cpp
        json_utility.h
        server_manager.cpp  server_manager.h
        ../external/httplib/httplib.h
        ../external/catch2/catch.hpp
        ../external/json11/json11.cpp ../external/json11/json11.hpp
)

target_link_libraries(rest_tester pthread)