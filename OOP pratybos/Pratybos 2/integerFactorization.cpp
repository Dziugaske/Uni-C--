#include "integerFactorization.hpp"

void IntegerFactorization::setInteger(int n){
    integer = n;
}
int IntegerFactorization::getInteger(){
    return integer;
}
void IntegerFactorization::factorize(){
    int factor = 2;
    int number = integer;
    while (number > 1){
        if (number % factor == 0){
            multiset.add(factor);
            number = number / factor;
        }
        else {
            ++factor;
        }
    }
}
std::string IntegerFactorization::toString(){
    std::ostringstream stream;
    stream << "Integer:" << std::endl;
    stream << integer << std::endl;
    stream << "Factorization:" << std::endl;
    stream << multiset.toString();
    return stream.str();
}