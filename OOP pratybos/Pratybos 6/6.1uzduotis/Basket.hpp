#ifndef BASKET_H
#define BASKET_H
#include "Blackcurrant.hpp"
#include <vector>
#include <memory>

class Basket {
    private:
    int capacity;
    std::vector<std::unique_ptr<Blackcurrant>> berries;
    Basket(int capacity);
    void addFruit(std::unique_ptr<Blackcurrant> berry);
    void emptyBasket();
    std::string getFruit() const;

    friend class Picker;
};
#endif