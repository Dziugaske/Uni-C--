#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "CentralProcessingUnit.h"

using namespace std;

int main() {
    CentralProcessingUnit cpu;
    CentralProcessingUnit cpu2;
    cpu.setCoreClock(123.45);
    cpu.setMultiplier(5);
    cpu2.setCoreClock(123.45);
    cpu2.setMultiplier(7);
    ++cpu;
    int temp = cpu.getMultiplier() + cpu2.getMultiplier();
    cout << temp << endl;
    cout << cpu.getMultiplier() << endl;
    return 0;
}