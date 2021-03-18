#ifndef BUSH_H
#define BUSH_H
#include "Blackcurrant.hpp"
#include <vector>
#include <memory>
#include <string>
#include <random>

class Bush {
  private:
    int yield;
    int qualityPercentage;
    std::vector<std::unique_ptr<Blackcurrant>> berries;
    std::mt19937 gen;
  public:
    //std::unique_ptr<Blackcurrant> growFruit();
    Bush(int yield, int qualityPercentage);
    void growFruit();
    void growYield();
    std::unique_ptr<Blackcurrant> removeFruit();
    std::string getFruit() const;
    int getFruitCount() const;
};
#endif