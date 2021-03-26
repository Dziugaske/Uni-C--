#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void printArray(vector<int> &array);
void checkCounts(int compareCount, int assignCount, vector<int> &array);
void selectionSort(vector<int> &array);
void insertionSort(vector<int> &array);
void gnomeSort(vector<int> &array);
void combSort(vector<int> &array);
void shellSort(vector<int> &array);
bool checked = false;
int main() {
    cout << "Hello World" << endl;
    vector<int> array = {7, 2, 6, 4, 8, 5, 3, 1};
    printArray(array);
    //selectionSort(array);
    //insertionSort(array);
    //gnomeSort(array);
    //combSort(array);
    shellSort(array);
    printArray(array);
    return 0;
}
void printArray(vector<int> &array) {
    for (int i = 0; i < array.size(); ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}
void checkCounts(int compareCount, int assignCount, vector<int> &array) {
    if (compareCount >= 10 && assignCount >= 5) {
        if (checked == false) {
            cout << "When 10 and 5 counts:" << endl;
            printArray(array);
            checked = true;
        }
    }
}
void selectionSort(vector<int> &array) {
    int compareCount = 0;
    int assignCount = 0;
    for (int i = 0; i < array.size() - 1; i++) {
        int min = i;
        for (int j = i + 1; j < array.size(); j++) {
            ++compareCount;
            checkCounts(compareCount, assignCount, array);
            if (array[j] < array[min]) {
                min = j;
                ++assignCount;
                checkCounts(compareCount, assignCount, array);
            }
        }
        if (min != i) {
            int temp = array[i];
            ++assignCount;
            checkCounts(compareCount, assignCount, array);
            array[i] = array[min];
            ++assignCount;
            checkCounts(compareCount, assignCount, array);
            array[min] = temp;
            ++assignCount;
            checkCounts(compareCount, assignCount, array);
        }
    }
    cout << "Compares: " << compareCount << endl;
    cout << "Assigns: " << assignCount << endl;
}
void insertionSort(vector<int> &array) {
    int compareCount = 0;
    int assignCount = 0;
    int i = 0;
    while (i < array.size()) {
        int j = i;
        ++compareCount;
        checkCounts(compareCount, assignCount, array);
        while (j > 0 && array[j - 1] > array[j]) {
            ++compareCount;
            checkCounts(compareCount, assignCount, array);
            int temp = array[j];
            ++assignCount;
            checkCounts(compareCount, assignCount, array);
            array[j] = array[j - 1];
            ++assignCount;
            checkCounts(compareCount, assignCount, array);
            array[j - 1] = temp;
            ++assignCount;
            checkCounts(compareCount, assignCount, array);
            --j;
        }
        ++i;
    }
    cout << "Compares: " << compareCount << endl;
    cout << "Assigns: " << assignCount << endl;
}
void gnomeSort(vector<int> &array) {
    int compareCount = 0;
    int assignCount = 0;
    int pos = 0;
    while (pos < array.size()) {
        ++compareCount;
        checkCounts(compareCount, assignCount, array);
        if (pos == 0 || array[pos] >= array[pos - 1]) {
            ++pos;
        } else {
            int temp = array[pos];
            ++assignCount;
            checkCounts(compareCount, assignCount, array);
            array[pos] = array[pos - 1];
            ++assignCount;
            checkCounts(compareCount, assignCount, array);
            array[pos - 1] = temp;
            ++assignCount;
            checkCounts(compareCount, assignCount, array);
            --pos;
        }
    }
    cout << "Compares: " << compareCount << endl;
    cout << "Assigns: " << assignCount << endl;
}
void combSort(vector<int> &array) {
    int compareCount = 0;
    int assignCount = 0;
    double gap = array.size();
    double shrink = 2;
    bool sorted = false;
    while (sorted == false) {
        gap = floor(gap / shrink);
        if (gap <= 1) {
            gap = 1;
            sorted = true;
        }
        int i = 0;
        while ((i + gap) < array.size()) {
            ++compareCount;
            checkCounts(compareCount, assignCount, array);
            if (array[i] > array[i + gap]) {
                int temp = array[i];
                ++assignCount;
                checkCounts(compareCount, assignCount, array);
                array[i] = array[i + gap];
                ++assignCount;
                checkCounts(compareCount, assignCount, array);
                array[i + gap] = temp;
                ++assignCount;
                checkCounts(compareCount, assignCount, array);
                sorted = false;
            }
            ++i;
        }
    }
    cout << "Compares: " << compareCount << endl;
    cout << "Assigns: " << assignCount << endl;
}
void shellSort(vector<int> &array) {
    int compareCount = 0;
    int assignCount = 0;
    int n = array.size();
    vector<int> gaps = {8, 4, 2, 1};
    for (const auto &gap : gaps) {
        for (int i = gap; i < n; ++i) {
            int temp = array[i];
            ++assignCount;
            checkCounts(compareCount, assignCount, array);
            int j;
            ++compareCount;
            checkCounts(compareCount, assignCount, array);
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap) {
                ++compareCount;
                checkCounts(compareCount, assignCount, array);
                array[j] = array[j - gap];
                ++assignCount;
                checkCounts(compareCount, assignCount, array);
            }
            array[j] = temp;
            ++assignCount;
            checkCounts(compareCount, assignCount, array);
        }
    }
    cout << "Compares: " << compareCount << endl;
    cout << "Assigns: " << assignCount << endl;
}