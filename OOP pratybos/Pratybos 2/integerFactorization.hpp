#ifndef FACTORIZATION
#define FACTORIZATION

#include "multiset.hpp"

class IntegerFactorization {
  
    int integer;
    Multiset multiset;
    
    public:

    void setInteger(int n);
    int getInteger();
    void factorize();
    std::string toString();
};

#endif