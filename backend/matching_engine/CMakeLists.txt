cmake_minimum_required(VERSION 3.0)
set (CMAKE_CXX_STANDARD 14)

set(ORDERBOOK_LIB orderbook.cpp)

add_subdirectory(order_book order_book)
add_subdirectory(order order)
add_subdirectory(quote quote)
add_subdirectory(trade trade)

add_executable(matching_engine_bin launcher.cpp)
target_link_libraries(matching_engine_bin order_book order quote)
