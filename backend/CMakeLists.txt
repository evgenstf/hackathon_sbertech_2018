cmake_minimum_required (VERSION 3.0)
project (simple_exchange)

set(CMAKE_CXX_STANDART 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

add_subdirectory(third_party_libraries/network/websocket_server websocket_server)

add_executable(simple_exchange_bin launcher.cpp)
target_link_libraries(simple_exchange_bin websocket_server pthread boost_system)
