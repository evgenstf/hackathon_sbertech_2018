#include "third_party_libraries/network/build_server.h"
#include <iostream>

using namespace std;

int main() {
  size_t port;
  cout << "enter port number: ";
  cin >> port;
  auto server = build_server(port);

  thread server_thread([&server]() {
    server->start();
  });
  clog << "server has been started at port: " << port << '\n';

  server_thread.join();
  return 0;
}
