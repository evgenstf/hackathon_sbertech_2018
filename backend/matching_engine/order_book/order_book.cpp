#include "order_book.h"

namespace NExchange {

OrderBook::OrderBook() {}
void OrderBook::add_order(const Order& order, EOrderType type) {
    switch (type) {
        case SELL:
            this->add_order(sell_, order);
            break;
        case BUY:
            this->add_order(buy_, order);
            break;
    }
}

void OrderBook::add_order(DirectionType& quots, const Order& order) {
    quots[order.get_price()].add_order(order);
}

const OrderBook::DirectionType& OrderBook::get_direction(EOrderType type) const {
    switch (type) {
        case SELL:
            return sell_;
        case BUY:
            return buy_;
    }
}

} //NExchange
