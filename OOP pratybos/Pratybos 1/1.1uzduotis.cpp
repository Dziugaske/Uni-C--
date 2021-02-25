#include <iostream>
#include <vector>

using namespace std;

void selectionSort(int *arrayPointer, int size){
    for (int i = 0; i < size - 1; i++){
        int min = i;
        for (int j = i + 1; j < size; j++){
            if (arrayPointer[j] < arrayPointer[min]){
                min = j;
            }
        }
        if (min != i){
            int temp = arrayPointer[i];
            arrayPointer[i] = arrayPointer[min];
            arrayPointer[min] = temp;
        }
    }
}
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

void printArray(int *arrayPointer, int size){
    for (int i = 0; i < size; i++){
        printf("%d ", arrayPointer[i]);
    }
    printf("\n");
}
void printVector(vector<int> &vectorArray, int size){
    for (int i = 0; i < size; i++){
        printf("%d ", vectorArray[i]);
    }
    printf("\n");
}
int main()
{
    int manualArray[10] = {4, 20, 14, -3, -6, -14, 0, 3, 1, 26};
    selectionSort(manualArray, 10);
    printArray(manualArray, 10);

    int userArray[1000];
    printf("Enter the numbers to array. Enter 0 to finish inputting numbers.\n");
    int counter = 0;
    while(1){
        int temp;
        scanf("%d", &temp);
        if (temp == 0){
            break;
        }
        userArray[counter] = temp;
        counter++;
    }
    selectionSort(userArray, counter);
    printArray(userArray, counter);

    vector<int> vectorArray;
    printf("Enter the numbers to array. Enter 0 to finish inputting numbers.\n");
    counter = 0;
    while(1){
        int temp;
        scanf("%d", &temp);
        if (temp == 0){
            break;
        }
        vectorArray.push_back(temp);
        counter++;
    }
    selectionSortVector(vectorArray, counter);
    printVector(vectorArray, counter);

}