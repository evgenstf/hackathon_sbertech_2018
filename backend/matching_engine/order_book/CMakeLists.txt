cmake_minimum_required(VERSION 3.0)
set (CMAKE_CXX_STANDARD 14)

set(ORDERBOOK_LIB orderbook.cpp)

add_library(order_book "order_book.cpp")
