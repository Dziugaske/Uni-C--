#include "Picker.hpp"

Picker::Picker(int productivity, int basketCapacity)
    : basket(basketCapacity) {
    if (productivity > 0) {
        this->productivity = productivity;
        income = 0;
    } else {
        throw std::invalid_argument("Productivity must be greater than 0");
    }
}
void Picker::collectFruit(Bush &bush) {
    gatheredCount = 0;
    while (bush.getFruitCount() != 0 && gatheredCount < productivity) {
        basket.addFruit(bush.removeFruit());
        ++gatheredCount;
    }
}
void Picker::emptyBasket() {
    basket.emptyBasket();
}
int Picker::getBerryCount() const {
    return gatheredCount;
}
void Picker::calculateIncome() {
    income += gatheredCount * Blackcurrant::getPrice();
}
double Picker::getIncome() const {
    return income;
}
std::string Picker::getFruit() const {
    return basket.getFruit();
}