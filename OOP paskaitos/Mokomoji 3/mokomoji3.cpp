#include "CentralProcessingUnit.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
using namespace cpu;

int main() {
    try {
        CentralProcessingUnit cpu("AMD", "Ryzen 3600");
        cpu.setCores(6);
        cpu.setTdp(450);
        cpu.setBaseClock(123.1);
        cpu.setMultiplier(13.4);
        cout << cpu.toString() << endl;

        vector<CentralProcessingUnit> cpuArray;
        for (int i = 1; i < 200; ++i) {
            cpuArray.push_back(CentralProcessingUnit("Intel", to_string(i * 100)));
            cpuArray[i - 1].setCores(i % 10 + 1);
            cpuArray[i - 1].setVoltage(i % 2 + 0.5);
            cpuArray[i - 1].setTdp(i * 5);
            cpuArray[i - 1].setBaseClock(i * 5);
            cpuArray[i - 1].setMultiplier(i % 49 + 1);
            cout << cpuArray[i - 1].toString() << endl;
        }
        //Testing all the get methods:
        cout << cpuArray[1].getCores() << endl;
        cout << cpuArray[1].getThreads() << endl;
        cout << cpuArray[1].getTdp() << endl;
        cout << cpuArray[1].getVoltage() << endl;
        cout << cpuArray[1].getBaseClock() << endl;
        cout << cpuArray[1].getMultiplier() << endl;
        cout << cpuArray[1].getCoreClock() << endl;
        //Throws an exception:
        cpuArray[5].setCores(-1);
    } catch (invalid_argument& e) {
        cout << e.what() << endl;
    } catch (...) {
        cout << "Unknown exeption occured." << endl;
    }
}