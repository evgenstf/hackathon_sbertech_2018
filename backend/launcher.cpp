#include "base/network/websocket_server/server_ws.hpp"
#include <iostream>

using WsServer = SimpleWeb::SocketServer<SimpleWeb::WS>;

using namespace std;

namespace {

auto build_server(size_t port) {
  auto server = make_unique<WsServer>();
  server->config.port = port;

  auto &echo = server->endpoint["^//?$"];

  echo.on_message = [](shared_ptr<WsServer::Connection> connection, shared_ptr<WsServer::Message> message) {
    auto message_str = message->string();

    clog << "server: message received: \"" << message_str << "\" from " << connection.get() << endl;

    clog << "server: sending message \"" << message_str << "\" to " << connection.get() << endl;

    auto send_stream = make_shared<WsServer::SendStream>();
    *send_stream << message_str;
    // connection->send is an asynchronous function
    connection->send(send_stream, [](const SimpleWeb::error_code &ec) {
      if(ec) {
        clog << "server: error sending message. " <<
            // See http://www.boost.org/doc/libs/1_55_0/doc/html/boost_asio/reference.html, Error Codes for error code meanings
            "error: " << ec << ", error message: " << ec.message() << endl;
      }
    });
  };

  echo.on_open = [](shared_ptr<WsServer::Connection> connection) {
    clog << "server: opened connection " << connection.get() << endl;
  };

  echo.on_close = [](shared_ptr<WsServer::Connection> connection, int status, const string & /*reason*/) {
    clog << "server: closed connection " << connection.get() << " with status code " << status << endl;
  };

  echo.on_error = [](shared_ptr<WsServer::Connection> connection, const SimpleWeb::error_code &ec) {
    clog << "server: error in connection " << connection.get() << ". "
         << "error: " << ec << ", error message: " << ec.message() << endl;
  };

  return server;
}

}  // namespace

int main() {
  auto server = build_server(5001);

  thread server_thread([&server]() {
    server->start();
  });
  clog << "server has been started\n";

  server_thread.join();
  return 0;
}
