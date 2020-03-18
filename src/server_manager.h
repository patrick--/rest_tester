#pragma once
#include <string>
#include <memory>
#include "http_utility.h"

using namespace http_utility;

class ServerManager {
public:
    ServerManager(std::string host="localhost", int port=8181);
    ~ServerManager();
    void add_handler(const HttpMethod, const std::string&, httplib::Server::Handler handler);
    void start();
    void stop();

private:
    int port_;
    std::string host_;
   httplib::Server server_;
};