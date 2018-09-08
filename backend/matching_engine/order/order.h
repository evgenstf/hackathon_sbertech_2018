#pragma once
#include <string>

namespace NExchange {

class Order {
public:
    Order();
    Order(const double& price, const unsigned long long& volume, const std::string& user);

    const double& get_price() const;
    const unsigned long long& get_volume() const;
    const std::string& get_user() const;

    double get_price();
    unsigned long long get_volume();
    std::string get_user();

private:
    double price_;
    unsigned long long volume_;
    std::string user_;
}; //Order

} //NExchange
