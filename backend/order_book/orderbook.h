#include <map>
#include <queue>
#include <string>

namespace NExchange {

enum EOrderType {
    SELL, BUY
};

using String = std::string;

template<typename KeyType>
using Queue = std::queue<KeyType>;

class Order {
public:
    Order();
    Order(const double& price, const unsigned long long& volume, const String& user);

    const double& get_price() const;
    const unsigned long long& get_volume() const;
    const String& get_user() const;

    double get_price();
    unsigned long long get_volume();
    String get_user();

private:
    double price_;
    unsigned long long volume_;
    String user_;
}; //Order

class Quot {
public:
    Quot();

    bool add_order(const Order& order);
    const double& get_price() const;
    const double& get_volume() const;

    bool empty() const;

private:
    void add_order_unsafe(const Order& order);
    void set_price(const double& price);

private:
    Queue<Order> orders_;
    double price_;
    double volume_;
}; //Quot


class OrderBook {
public:
    OrderBook();
    
    using DirectionType = std::map<double, Quot>;

    void add_order(const Order& order, EOrderType type);
    const DirectionType& get_direction(EOrderType type) const;

private:
    void add_order(DirectionType& quots, const Order& order);

private:
    DirectionType sell_;
    DirectionType buy_;
};

} //NExchange
