#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class FirstImplementation {
    private:
        vector<int> array = vector<int>(10, 0);
        int lCount = 0;
        int rCount = 0;
        int sizeCount = 0;
    public:
        void add(int index, int value) {
            if (sizeCount < index) {
                ++lCount;
                ++sizeCount;
                array[index] = value;
            } else {
                for (int i = sizeCount + 1; i > index; --i) {
                    ++lCount;
                    ++rCount;
                    array[i] = array[i - 1];
                }
                ++lCount;
                ++sizeCount;
                array[index] = value;
            }
        }
        int get(int index) {
            ++rCount;
            return array[index];
        }
        void del(int index) {
            for (int i = index; i < sizeCount; ++i) {
                ++lCount;
                ++rCount;
                array[i] = array[i + 1];
            }
            --sizeCount;
        }
        int size() {
            return sizeCount;
        }
        string toString() {
            ostringstream ss;
            for (int i = 1; i <= sizeCount; ++i){
                ss << array[i] << endl;
            }
            ss << "LV: " << lCount << " RV: " << rCount;
            return ss.str();
        }
};

int main() {
    FirstImplementation first;
    first.add(1, 4);
    first.add(1, 5);
    first.get(2);
    first.add(2, 3);
    first.del(1);
    first.add(1, 6);
    first.del(1);
    first.size();
    first.get(1);
    cout << first.toString();
}