#ifndef MULTISET
#define MULTISET

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

class Multiset {
  
    std::vector<int> elements;
    std::vector<int> counts;

    public:

    void add(int element);
    std::string toString();
    int size();
    void remove(int element);
};

#endif