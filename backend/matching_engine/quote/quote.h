#pragma once
#include "../order/order.h"
#include <queue>

namespace NExchange {
class Quote {
public:
    Quote();

    bool add_order(const Order& order);
    const double& get_price() const;
    const double& get_volume() const;

    bool empty() const;

private:
    void add_order_unsafe(const Order& order);
    void set_price(const double& price);

private:
    std::queue<Order> orders_;
    double price_;
    double volume_;
}; //Quote

} //NExchange
