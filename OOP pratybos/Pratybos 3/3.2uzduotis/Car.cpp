#include <iostream>
#include <string>
#include <sstream>
#include "Car.hpp"

using namespace std;

int Car::carCount = 0;
Car::Car() {
    setMileage(0);
    setCrashed(false);
    ++carCount;
}
Car::Car(std::string modelName) {
    setModelName(modelName);
    setMileage(0);
    setCrashed(false);
    ++carCount;
}
Car::Car(std::string modelName, int mileage, bool crashed) {
    setModelName(modelName);
    setMileage(mileage);
    setCrashed(crashed);
    ++carCount;
}
Car::Car(std::string modelName, int mileage, bool crashed, Date registryDate) {
    setModelName(modelName);
    setMileage(mileage);
    setCrashed(crashed);
    this->registryDate = registryDate;
    ++carCount;
}
Car::~Car() {
    --carCount;
}
int Car::getCount() {
    return carCount;
}
void Car::setModelName(std::string modelName) {
    this->modelName = modelName;
}
void Car::setMileage(int mileage) {
    if (mileage >= 0){
        this->mileage = mileage;
    } else {
        throw "Incorrect mileage";
    }
    
}
void Car::setCrashed(bool crashed) {
    this->crashed = crashed;
}
std::string Car::getModelName() {
    ostringstream ss;
    ss << modelName;
    return ss.str();
}
int Car::getMileage() {
    return mileage;
}
bool Car::getCrashed() {
    return crashed;
}
std::string Car::getDate() {
    return registryDate.showDateLT();
}
void Car::adjustDate(int value) {
    for (int i = 0; i < value; ++i) {
        registryDate.incrementDate();
    }
}