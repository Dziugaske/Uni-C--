#include "Basket.hpp"
#include <memory>
#include <sstream>

Basket::Basket(int capacity) {
    if (capacity > 0) {
        this->capacity = capacity;
    } else {
        throw std::invalid_argument ("Capacity must be greater than 0");
    }
}
void Basket::addFruit(std::unique_ptr<Blackcurrant> berry) {
    berries.push_back(std::move(berry));
    if (berries.size() == capacity) {
        emptyBasket();
    }
}
void Basket::emptyBasket() {
    for (int i = berries.size() - 1; i >= 0; --i) {
        berries[i].reset();
        berries.pop_back();
    }
}
std::string Basket::getFruit() const {
    std::stringstream ss;
    for (const auto &berry : berries) {
        ss << berry->getWeight() << " ";
        ss << berry->getQualityPercentage() << " ";
    }
    return ss.str();
}