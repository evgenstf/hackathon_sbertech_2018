#include "websocket_server/server_ws.hpp"

using WsServer = SimpleWeb::SocketServer<SimpleWeb::WS>;

auto build_server(size_t port) {
  auto server = std::make_unique<WsServer>();
  server->config.port = port;

  auto &echo = server->endpoint["^//?$"];

  echo.on_message = [](std::shared_ptr<WsServer::Connection> connection, std::shared_ptr<WsServer::Message> message) {
    auto message_str = message->string();

    std::clog << "server: message received: \"" << message_str << "\" from " << connection.get() << '\n';

    std::clog << "server: sending message \"" << message_str << "\" to " << connection.get() << '\n';

    auto send_stream = std::make_shared<WsServer::SendStream>();
    *send_stream << message_str;
    // connection->send is an asynchronous function
    connection->send(send_stream, [](const SimpleWeb::error_code &ec) {
      if(ec) {
        std::clog << "server: error sending message. " <<
            // See http://www.boost.org/doc/libs/1_55_0/doc/html/boost_asio/reference.html, Error Codes for error code meanings
            "error: " << ec << ", error message: " << ec.message() << '\n';
      }
    });
  };

  echo.on_open = [](std::shared_ptr<WsServer::Connection> connection) {
    std::clog << "server: opened connection " << connection.get() << '\n';
  };

  echo.on_close = [](std::shared_ptr<WsServer::Connection> connection, int status, const std::string & /*reason*/) {
    std::clog << "server: closed connection " << connection.get() << " with status code " << status << '\n';
  };

  echo.on_error = [](std::shared_ptr<WsServer::Connection> connection, const SimpleWeb::error_code &ec) {
    std::clog << "server: error in connection " << connection.get() << ". "
         << "error: " << ec << ", error message: " << ec.message() << '\n';
  };

  return server;
}
