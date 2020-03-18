
#include "handlers.h"
#include <iostream>
namespace handlers {
void hello_world(const httplib::Request &req, httplib::Response &res) {
  res.status = 200;
  res.set_content("Hello World", "text/plain");
}

void echo(const httplib::Request &req, httplib::Response &res) {}

void get_http_response(const httplib::Request &req, httplib::Response &res) {
  int resp_code = 500;

  if (req.has_param("http_resp_code")) {
    auto param_val = req.get_param_value("http_resp_code");
    if (http_utility::is_valid_status(param_val)) {
      resp_code = std::stoi(param_val);
    }
  }
  res.status = resp_code;
}
} // namespace handlers