#include "trade.h"

namespace NExchange {

Trade::Trade() {}
Trade::Trade(const double& price, const double& volume, const std::string& aggressor_dir)
    : price_(price), volume_(volume), aggressor_dir_(aggressor_dir) {}

const double& Trade::price() const {
    return price_;
}

const double& Trade::volume() const {
    return volume_;
}

const std::string& Trade::aggressor_dir() const {
    return aggressor_dir_;
}

double Trade::price() {
    return price_;
}

double Trade::volume() {
    return volume_;
}

std::string Trade::aggressor_dir() {
    return aggressor_dir_;
}

} //Nexchange
