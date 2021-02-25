#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>

using namespace std::chrono;

int main(){
    int size = 100000;
    int randomArray[size];
    double answerArray[size];
    for (int i = 0; i < size; ++i){
        randomArray[i] = rand() % 100000 + 1;
    }

    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < size - 1; ++i){
        for (int o = 0; o < size - 1; ++o){
            answerArray[o] = randomArray[o] + randomArray[o + 1];
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    
    std::cout << "Time taken: " << duration.count() << " microseconds" << std::endl;
}