#include "CentralProcessingUnit.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
using namespace cpu;

int main() {
    CentralProcessingUnit cpu("AMD", "Ryzen 3600");
    cpu.setCores(6);
    cpu.setTdp(450);
    cpu.setBaseClock(123.1);
    cpu.setMultiplier(13.4);
    cout << cpu.toString();

    vector<CentralProcessingUnit> cpuArray;
    for (int i = 3000; i < 9000; i += 100) {
        cpuArray.push_back(CentralProcessingUnit("Intel", to_string(i)));
    }
    cout << cpuArray[9].toString();
}