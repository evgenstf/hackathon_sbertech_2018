#include "order.h"

namespace NExchange {

Order::Order() {}
Order::Order(const double& price, const unsigned long long& volume, const std::string& user)
    : price_(price), volume_(volume), user_(user) {}

const double& Order::get_price() const {
    return price_;
}

const unsigned long long& Order::get_volume() const {
    return volume_;
}

const std::string& Order::get_user() const {
    return user_;
}

double Order::get_price() {
    return price_;
}

unsigned long long Order::get_volume() {
    return volume_;
}

std::string Order::get_user() {
    return user_;
}


} //NExchange
