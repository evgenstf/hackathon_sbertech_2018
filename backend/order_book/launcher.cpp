#include "orderbook.h"
#include <iostream>

void print_direction(const NExchange::OrderBook::DirectionType& direction) {
    for (const auto& entry: direction) {
        const auto& price = entry.first;
        const auto& volume = entry.second.get_volume();
        std::cout << "price = " << price << ", volume = " << volume << std::endl;
    }
}


void print(const NExchange::OrderBook& orderbook) {
    const auto& sell = orderbook.get_direction(NExchange::SELL);
    const auto& buy = orderbook.get_direction(NExchange::BUY);

    std::clog << "sell --------------" << std::endl;
    print_direction(sell);
    std::clog << "buy ---------------" << std::endl;
    print_direction(buy);
}

int main() {
    NExchange::OrderBook a;
    NExchange::Order b(10, 2, "Maxim");
    NExchange::Order c(20, 4, "Zhenya");

    a.add_order(b, NExchange::SELL);
    a.add_order(c, NExchange::BUY);

    print(a);
}
