#pragma once

#include "http_utility.h"

namespace handlers {
    
    void hello_world(const httplib::Request&, httplib::Response&);
    void echo(const httplib::Request&, httplib::Response&);
    void http_response(const httplib::Request&, httplib::Response&);
}