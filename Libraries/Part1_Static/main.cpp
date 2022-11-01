#include "library.h"
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int main(){
    int output = library::addFive(-5);
    printf("Output: %d\n", output);
    //cout << library::addFive(output) << endl;

    int X[] = {1,2,3};
    int Y[] = {4,5,6};

    int* array;
    array = library::combineIntArrays(X, 3, Y, 3);
    int size = 6;
    
    for (int i = 0; i < size; i++) {
        cout << array[i] << "\t";
    }
    cout << endl;

    return 0;
}