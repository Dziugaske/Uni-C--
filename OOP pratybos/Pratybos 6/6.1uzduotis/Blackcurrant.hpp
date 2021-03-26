#ifndef BLACKCURRANT_H
#define BLACKCURRANT_H
#include "Date.hpp"

class Blackcurrant {
  private:
    static float price;
    float weight;
    int qualityPercentage;
    Date growDate;

  public:
    Blackcurrant(float weight, int qualityPercentage);
    static void setPrice(float value);
    static float getPrice();
    float getWeight() const;
    int getQualityPercentage() const;
};
#endif