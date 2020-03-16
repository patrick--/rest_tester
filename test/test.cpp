#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "server_manager.h"

const int test_port = 8181;
const std::string test_host = "localhost";

ServerManager dev_server("localtesthost", 8181);

TEST_CASE("Testing basic handlers") {
    REQUIRE(1 == 1);
}