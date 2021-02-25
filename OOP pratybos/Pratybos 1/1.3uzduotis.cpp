#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>

using namespace std;

void selectionSortVector(vector<int> &vectorArray, int size){
    for (int i = 0; i < size - 1; i++){
        int min = i;
        for (int j = i + 1; j < size; j++){
            if (vectorArray[j] < vectorArray[min]){
                min = j;
            }
        }
        if (min != i){
            int temp = vectorArray[i];
            vectorArray[i] = vectorArray[min];
            vectorArray[min] = temp;
        }
    }
}
void randomArray(vector<int> &vectorArray, int size){
    vectorArray.clear();
    for (int i = 0; i < size; i++){
        vectorArray.push_back(rand());
    }
}
void printVector(vector<int> &vectorArray, int size){
    for (int i = 0; i < size; i++){
        printf("%d ", vectorArray[i]);
    }
    printf("\n");
}

int main()
{
    vector<int> vectorArray;
    srand(time(0));
    clock_t t;
    std::ofstream  ofs ("time.txt");


    for (int size = 10000; size <= 100900; size += 1000){
        randomArray(vectorArray, size);
        t = clock();
        selectionSortVector(vectorArray, size);
        t = clock() - t;
        double selectionTime = ((double)t)/CLOCKS_PER_SEC;
        cout << size << " " << selectionTime << endl;
        ofs << size << " " << selectionTime << endl;
    }
    ofs.close();
}