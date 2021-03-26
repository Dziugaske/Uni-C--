#include "Bush.hpp"
#include <random>
#include <sstream>
#include <chrono>

Bush::Bush(int yield, int qualityPercentage) {
    if (yield > 0) {
        if (qualityPercentage >= 0 && qualityPercentage <= 100) {
            this->yield = yield;
            this->qualityPercentage = qualityPercentage;
            std::mt19937 temp(time(0));
            gen = temp;
        } else {
            throw std::invalid_argument("Quality percentage must be between 0 and 100");
        }
    } else {
        throw std::invalid_argument("Yield can't be negative or 0");
    }
}
void Bush::growFruit() {
    std::uniform_real_distribution<float> weightDis(0.2, 2.0);
    std::uniform_int_distribution<int> qualityDis(0, qualityPercentage);
    berries.push_back(std::make_unique<Blackcurrant>(weightDis(gen), qualityDis(gen)));
}
void Bush::growYield() {
    for (int i = 0; i < yield; ++i) {
        growFruit();
    }
}
std::unique_ptr<Blackcurrant> Bush::removeFruit() {
    std::unique_ptr<Blackcurrant> temp = std::move(berries.back());
    berries.pop_back();
    return std::move(temp);
}
std::string Bush::getFruit() const {
    std::stringstream ss;
    for (const auto &berry : berries) {
        ss << berry->getWeight() << " ";
        ss << berry->getQualityPercentage() << " ";
    }
    return ss.str();
}
int Bush::getFruitCount() const {
    return berries.size();
}