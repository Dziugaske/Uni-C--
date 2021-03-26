#include "Blackcurrant.hpp"
#include <stdexcept>

Blackcurrant::Blackcurrant(float weight, int qualityPercentage) {
    if (weight > 0) {
        if (qualityPercentage >= 0 && qualityPercentage <= 100) {
            this->weight = weight;
            this->qualityPercentage = qualityPercentage;
        } else {
            throw std::invalid_argument("Quality percentage must be between 0 and 100");
        }
    } else {
        throw std::invalid_argument("Weight can't be negative or 0");
    }
}
float Blackcurrant::price = 0;
void Blackcurrant::setPrice(float value) {
    if (value > 0) {
        price = value;
    } else {
        throw std::invalid_argument("Price can't be negative or 0");
    }
}
float Blackcurrant::getPrice() {
    return price;
}
float Blackcurrant::getWeight() const {
    return weight;
}
int Blackcurrant::getQualityPercentage() const {
    return qualityPercentage;
}