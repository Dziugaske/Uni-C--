#include "CentralProcessingUnit.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    CentralProcessingUnit cpu;
    cin >> cpu;
    cout << cpu << endl;
    CentralProcessingUnit cpu2;
    cpu2.setCoreClock(3200);
    bool comparison = cpu > cpu2;
    cout << comparison;

    ++cpu;
    cout << cpu << endl;
    return 0;
}