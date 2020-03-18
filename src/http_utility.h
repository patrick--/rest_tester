#pragma once

#include <string>
#include "httplib.h"
#include "json11.hpp"

namespace http_utility {

    enum class HttpMethod {
        Get, Post, Put, Patch, Delete
    };

    bool is_valid_status(const std::string&);

}


