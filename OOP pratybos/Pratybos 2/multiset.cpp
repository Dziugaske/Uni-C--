#include "multiset.hpp"

void Multiset::add(int element){
    int setPlace = 0;
    bool foundElement = false;
    for (int i = 0; i < elements.size(); ++i){
        if (elements[i] == element){
            setPlace = i;
            foundElement = true;
            break;
        }
    }
    if (foundElement == false){
        elements.push_back(element);
        counts.push_back(1);
    }
    else {
        ++counts[setPlace];
    }
}
std::string Multiset::toString(){
    std::ostringstream stringStream;
    for (int i = 0; i < elements.size(); ++i){
        stringStream << elements[i] << " " << counts[i] << std::endl;
    }
    return stringStream.str();
}
void Multiset::remove(int element){
    for (int i = 0; i < elements.size(); ++i){
        if (element == elements[i]){
            elements.erase(elements.begin() + i);
            counts.erase(counts.begin() + i);
            break;
        }
    }
}
int Multiset::size(){
    return elements.size();
}
