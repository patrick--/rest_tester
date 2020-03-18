#include "server_manager.h"
#include <stdexcept>

ServerManager::ServerManager(std::string host, int port)
    : port_(port), host_(host) {
  if (!server_.is_valid()) {
    throw std::runtime_error("Unable to create HTTP server");
  }

  add_handler(HttpMethod::Get, "/stop",
              [this](const httplib::Request &req, httplib::Response &res) {
                server_.stop();
              });
}

ServerManager::~ServerManager() { server_.stop(); }

void ServerManager::start() {
  server_.listen(host_.c_str(), port_);
  if (!server_.is_running()) {
    throw std::runtime_error("Unable to start HTTP server");
  }
}

void ServerManager::add_handler(const HttpMethod method,
                                const std::string &route,
                                httplib::Server::Handler h) {
  const auto route_cstr = route.c_str();

  switch (method) {
  case HttpMethod::Get:
    server_.Get(route_cstr, h);
    break;

  case HttpMethod::Post:
    server_.Post(route_cstr, h);
    break;

  case HttpMethod::Patch:
    server_.Patch(route_cstr, h);
    break;

  case HttpMethod::Put:
    server_.Put(route_cstr, h);
    break;

  case HttpMethod::Delete:
    server_.Delete(route_cstr, h);
    break;
  }
}

void ServerManager::stop() { server_.stop(); }