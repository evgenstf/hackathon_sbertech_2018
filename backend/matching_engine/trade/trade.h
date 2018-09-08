#pragma once
#include <string>
namespace NExchange {

class Trade {
public:
    Trade();
    Trade(const double& price, const double& volume, const std::string& aggressor_dir);

    const double& price() const;
    const double& volume() const;
    const std::string& aggressor_dir() const;

    double price();
    double volume();
    std::string aggressor_dir();

private:
    double price_;
    double volume_;
    std::string aggressor_dir_;
};

} //NExchange
