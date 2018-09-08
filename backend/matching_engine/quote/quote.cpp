#include "quote.h"

namespace NExchange {
Quote::Quote() {}

bool Quote::empty() const {
    return orders_.empty();
}

bool Quote::add_order(const Order& order) {
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

void Quote::set_price(const double& price) {
    price_ = price;
}

const double& Quote::get_price() const {
    return price_;
}

const double& Quote::get_volume() const {
    return volume_;
}

void Quote::add_order_unsafe(const Order& order) {
    orders_.push(order);
    volume_ += order.get_volume();
}

} //NExchange
