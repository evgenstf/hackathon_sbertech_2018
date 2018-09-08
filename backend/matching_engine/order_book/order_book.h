#pragma once
#include "../order/order.h"
#include "../quote/quote.h"

#include <map>

namespace NExchange {

enum EOrderType {
    SELL, BUY
};

template<typename KeyType>
using Queue = std::queue<KeyType>;


class OrderBook {
public:
    OrderBook();
    
    using DirectionType = std::map<double, Quote>;

    void add_order(const Order& order, EOrderType type);
    const DirectionType& get_direction(EOrderType type) const;

private:
    void add_order(DirectionType& quots, const Order& order);

private:
    DirectionType sell_;
    DirectionType buy_;
};

} //NExchange
