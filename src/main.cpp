#include "handlers.h"
#include "server_manager.h"

int main() {

  ServerManager s("localhost", 8999);

  s.add_handler(HttpMethod::Get, "/hello_world", handlers::hello_world);
  s.add_handler(HttpMethod::Get, "/echo", handlers::echo);
  s.add_handler(HttpMethod::Get, "/http_response", handlers::get_http_response);

  s.start();
}
