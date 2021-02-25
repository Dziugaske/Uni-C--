#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "integerFactorization.hpp"

using namespace std;

int main(){
    IntegerFactorization factorization;
    factorization.setInteger(39);
    factorization.factorize();
    cout << factorization.toString();
}