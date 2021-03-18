#ifndef PICKER_H
#define PICKER_H
#include "Basket.hpp"
#include "Bush.hpp"

class Picker {
    private:
    int productivity;
    int gatheredCount;
    Basket basket;
    double income;
    public:
    Picker(int productivity, int basketCapacity);
    void collectFruit(Bush &bush);
    void emptyBasket();
    int getBerryCount() const;
    void calculateIncome();
    double getIncome() const;
    std::string getFruit() const;
};
#endif