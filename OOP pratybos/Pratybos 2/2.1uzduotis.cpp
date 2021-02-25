//C multiset structure

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct multiset {
    vector<int> elements;
    vector<int> counts;
};

void multiset_add(multiset &set, int element);
string multiset_toString(multiset set);

int main(){
    multiset set;

    vector<int> initialSet{4, 2, 1, 2, 4, 5, 5, 5, 7, 1, 3};
    for (int i = 0; i < initialSet.size(); ++i){
        multiset_add(set, initialSet[i]);
    }
    cout << multiset_toString(set);

}
void multiset_add(multiset &set, int element){
    int setPlace = 0;
    bool foundElement = false;
    for (int i = 0; i < set.elements.size(); ++i){
        if (set.elements[i] == element){
            setPlace = i;
            foundElement = true;
            break;
        }
    }
    if (foundElement == false){
        set.elements.push_back(element);
        set.counts.push_back(1);
    }
    else {
        ++set.counts[setPlace];
    }
}
string multiset_toString(multiset set){
    ostringstream stringStream;
    for (int i = 0; i < set.elements.size(); ++i){
        stringStream << set.elements[i] << " " << set.counts[i] << endl;
    }
    return stringStream.str();
}
