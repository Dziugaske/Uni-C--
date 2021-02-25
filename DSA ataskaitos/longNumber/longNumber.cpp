#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "largeInteger.h"

using namespace std;

int main() {
    try {
        LargeInteger foo("54124124124124234489538947289472389472893748923749823723859023785092385902385902385902839058923859023859023895082390585");
        LargeInteger bar("5238590283590782905890879045878693485902385902890589068390689034869038690834906839046890348690384690346");
        LargeInteger foobar = foo + bar;
        cout << foo.toString() << endl;
        cout << bar.toString() << endl;
        cout << foobar.toString() << endl;
    } catch (...) {
        cout << "Exception caught!." << endl;
    }
}