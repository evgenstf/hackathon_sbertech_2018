#include "orderbook.h"

namespace NExchange {
    
    ///////////////////////////////////////////////////
Order::Order() {}
Order::Order(const double& price, const unsigned long long& volume, const String& user)
    : price_(price), volume_(volume), user_(user) {}

const double& Order::get_price() const {
    return price_;
}

const unsigned long long& Order::get_volume() const {
    return volume_;
}

const String& Order::get_user() const {
    return user_;
}

double Order::get_price() {
    return price_;
}

unsigned long long Order::get_volume() {
    return volume_;
}

String Order::get_user() {
    return user_;
}
///////////////////////////////////////////////////


///////////////////////////////////////////////////
Quot::Quot() {}

bool Quot::empty() const {
    return orders_.empty();
}

bool Quot::add_order(const Order& order) {
    if (this->empty()) {
        this->set_price(order.get_price());
        this->add_order_unsafe(order);
        return true;
    } else {
        if (this->get_price() != order.get_price()) {
            return false;
        } else {
            this->add_order_unsafe(order);
        }
    }
    return true; 
}

void Quot::set_price(const double& price) {
    price_ = price;
}

const double& Quot::get_price() const {
    return price_;
}

const double& Quot::get_volume() const {
    return volume_;
}

void Quot::add_order_unsafe(const Order& order) {
    orders_.push(order);
    volume_ += order.get_volume();
}
///////////////////////////////////////////////////


///////////////////////////////////////////////////
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
//////////////////////////////////////////////////



} //NExchange
