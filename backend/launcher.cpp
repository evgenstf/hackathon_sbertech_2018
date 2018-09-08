#include "base/network/build_server.h"
#include <iostream>

using namespace std;

int main() {
  auto server = build_server(5001);

  thread server_thread([&server]() {
    server->start();
  });
  clog << "server has been started\n";

  server_thread.join();
  return 0;
}
