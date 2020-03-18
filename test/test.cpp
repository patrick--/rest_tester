#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "handlers.h"
#include "httplib.h"
#include <string>

using namespace httplib;
using namespace json11;

TEST_CASE("Testing basic GET handlers") {

  Request req;
  Response resp;
  Json json_resp;
  Json json_req;
  std::string json_parse_error;

  SECTION("Testing hello_world handler") {
    req.method = "GET";
    req.path = "/hello_world";

    handlers::hello_world(req, resp);

    REQUIRE(resp.status == 200);
    REQUIRE(resp.body == "Hello World");
  }

  SECTION("Testing echo handler") {

    req.method = "GET";
    req.path = "/echo";
    req.headers.insert(std::make_pair("header_key_1", "header_value_1"));
    req.body = "test body 123";
    req.version = "HTTP/1.1";
    req.target = "/echo";
    req.params.insert(std::make_pair("param_key_1", "param_value_1"));

    handlers::echo(req, resp);

    REQUIRE(resp.status == 200);

    json_resp = Json::parse(resp.body, json_parse_error);

    REQUIRE(json_parse_error.length() == 0);

    REQUIRE(json_resp["method"].string_value() == "GET");
    REQUIRE(json_resp["path"].string_value() == "/echo");
    REQUIRE(json_resp["headers"]["header_key_1"].string_value() ==
            "header_value_1");
    REQUIRE(json_resp["body"].string_value() == "test body 123");
    REQUIRE(json_resp["version"].string_value() == "HTTP/1.1");
    REQUIRE(json_resp["target"].string_value() == "/echo");
    REQUIRE(json_resp["params"]["param_key_1"].string_value() ==
            "param_value_1");
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