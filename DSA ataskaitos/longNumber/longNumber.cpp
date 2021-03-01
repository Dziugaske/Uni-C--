#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "largeInteger.h"

using namespace std;

int main() {
    try {
        LargeInteger foo("50");
        LargeInteger bar("50");
        LargeInteger foobar = foo + bar;
        cout << foo.toString() << endl;
        cout << bar.toString() << endl;
        cout << foobar.toString() << endl;
    } catch (...) {
        cout << "Exception caught!." << endl;
    }
}