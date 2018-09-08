cmake_minimum_required(VERSION 3.0)
set (CMAKE_CXX_STANDARD 11)

set(ORDERBOOK_LIB orderbook.cpp)
add_library(order_book ${ORDERBOOK_LIB})

add_executable(order_book_bin launcher.cpp)
target_link_libraries(order_book_bin order_book)
