#include "Bush.hpp"
#include "Picker.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <chrono>
using namespace std;

int main() {
    try {
        int days = 20;
        std::mt19937 gen(time(0));
        std::uniform_real_distribution<float> priceDis(0.1, 3.0);
        Blackcurrant::setPrice(priceDis(gen));

        Bush bush1(4124, 100);
        Bush bush2(241, 20);
        Bush bush3(23525, 60);
        Picker picker1(40, 30);
        Picker picker2(30, 10);
        Picker picker3(20, 20);
        for (int i = 1; i <= days; ++i) {
            bush1.growYield();
            bush2.growYield();
            bush3.growYield();
            picker1.collectFruit(bush1);
            picker2.collectFruit(bush2);
            picker3.collectFruit(bush3);
            cout << "Results for day " << i << endl;
            cout << "Berries gathered:" << endl;
            cout << picker1.getBerryCount() << " " << picker2.getBerryCount() << " " << picker3.getBerryCount() << endl;
            cout << "Berries remaining on bushes:" << endl;
            cout << bush1.getFruitCount() << " " << bush2.getFruitCount() << " " << bush3.getFruitCount() << " " << endl;
            picker1.calculateIncome();
            picker2.calculateIncome();
            picker3.calculateIncome();
            cout << "Total income for each picker:" << endl;
            cout << picker1.getIncome() << " " << picker2.getIncome() << " " << picker3.getIncome() << endl;
            Blackcurrant::setPrice(priceDis(gen));
        }
    } catch (invalid_argument &e) {
        cerr << e.what();
    } catch (...) {
        cerr << "Unexpected exception";
    }

    return 0;
}