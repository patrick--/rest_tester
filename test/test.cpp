#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "handlers.h"
#include "httplib.h"

using namespace httplib;
using namespace json11;

TEST_CASE("Testing basic GET handlers") {

  Request req;
  Response resp;

  SECTION("Testing hello_world handler") {
    req.method = "GET";
    req.path = "/hello_world";

    handlers::hello_world(req, resp);

    REQUIRE(resp.status == 200);
    REQUIRE(resp.body == "Hello World");
  }

  SECTION("Testing get_http_response handler") {
    req.method = "GET";
    req.path = "/get_http_response";
    req.params.insert(std::make_pair("http_resp_code", "200"));

    handlers::get_http_response(req, resp);
    REQUIRE(resp.status == 200);

    // Passing an invalid status code should return default of 500
    req.params.clear();
    req.params.insert(std::make_pair("http_resp_code", "666"));

    handlers::get_http_response(req, resp);
    REQUIRE(resp.status == 500);
  }
}