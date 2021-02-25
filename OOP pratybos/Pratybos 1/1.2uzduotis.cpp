#include <iostream>
#include <fstream>
#include <vector>
#include <string>


void selectionSortVector(std::vector<std::string> &vectorArray, int size){
    for (int i = 0; i < size - 1; i++){
        int min = i;
        for (int j = i + 1; j < size; j++){
            if (vectorArray[j] < vectorArray[min]){
                min = j;
            }
        }
        if (min != i){
            swap(vectorArray[i], vectorArray[min]);
        }
    }
}

void printVector(std::vector<std::string> &vectorArray, int size){
    for (int i = 0; i < size; i++){
        std::cout << vectorArray[i] << std::endl;
    }
    printf("\n");
}
void outputVector(std::vector<std::string> &vectorArray, int size){
    std::ofstream  ofs ("out.txt");
    for (int i = 0; i < size; i++){
        ofs << vectorArray[i] << std::endl;
    }
    ofs.close();
}
int main()
{

    std::vector<std::string> vectorArray;
    printf("Enter the names to array. Enter - to finish inputting names.\n");
    int counter = 0;
    while(1){
        std::string temp;
        getline(std::cin, temp);
        if (!temp.compare("-")){
            break;
        }
        vectorArray.push_back(temp);
        counter++;
    }
    selectionSortVector(vectorArray, counter);
    printVector(vectorArray, counter);
    outputVector(vectorArray, counter);
}