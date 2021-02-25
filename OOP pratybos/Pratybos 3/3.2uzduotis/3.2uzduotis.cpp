#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "Car.hpp"

using namespace std;

int main(){
    vector<Car*> vehicleArray;
    
    cout << Car::getCount() << endl;
    Car *vehicle1 = new Car;
    Car *vehicle2 = new Car;
    Car *vehicle3 = new Car;

    vehicleArray.push_back(vehicle2);
    vehicleArray.push_back(vehicle2);
    vehicleArray.push_back(vehicle3);
    cout << Car::getCount() << endl;

    delete vehicle1;
    delete vehicle2;
    cout << Car::getCount() << endl;
    delete vehicle3;
}