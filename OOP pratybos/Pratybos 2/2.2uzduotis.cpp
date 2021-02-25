#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "multiset.hpp"

using namespace std;

int main(){
    Multiset set;
    vector<int> initialSet{4, 2, 1, 2, 4, 5, 5, 5, 7, 1, 3};
    for (int i = 0; i < initialSet.size(); ++i){
        set.add(initialSet[i]);
    }
    int element;

    cout << "Add a number to the multiset:" << endl;
    cin >> element;
    set.add(element);

    cout << "Remove a number from the multiset:" << endl;
    cin >> element;
    set.remove(element);
    cout << "Size of the multiset:" <<set.size() << endl;
    cout <<set.toString();

    cout << "Remove a number from the multiset:" << endl;
    cin >> element;
    set.remove(element);
    cout << "Size of the multiset:" <<set.size() << endl;
    cout << set.toString();
}