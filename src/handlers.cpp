#include "handlers.h"

namespace handlers {
void hello_world(const httplib::Request &req, httplib::Response &res) {
  res.status = 200;
  res.set_content("Hello World", "text/plain");
}

void echo(const httplib::Request &req, httplib::Response &res) {
  json11::Json test =
      json11::Json::object{{"method", req.method},
                           {"path", req.path},
                           {"headers", json11::Json::array{req.headers}[0]},
                           {"body", req.body},
                           {"version", req.version},
                           {"target", req.target},
                           {"params", json11::Json::array{req.params}[0]}

      };
  res.status = 200;
  res.set_content(test.dump(), "application/json");
}

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