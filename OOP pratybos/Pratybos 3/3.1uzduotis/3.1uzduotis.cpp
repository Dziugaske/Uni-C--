#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "Date.hpp"

using namespace std;

int main(){
    try {
        Date foo;
        cout << foo.showDateLT() << endl;
        Date bar(2020, 2, 29);
        cout << bar.showDateUS() << endl;
        bar.incrementDate();
        cout << bar.showDateLT() << endl;
    } catch (...) {
        cout << "Impossible date." << endl;
    }
}