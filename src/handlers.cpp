
#include "handlers.h"

namespace handlers {

    void hello_world(const httplib::Request& req, httplib::Response& res)
    {
        res.set_content("Hello World", "text/plain");
    }

}