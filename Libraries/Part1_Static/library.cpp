#include "library.h"
#include <algorithm>

int library::addFive(int number){
    return number + 5;
}

int library::pow(int base, int power){
    int retVal;
    for(int i = 0; i < power; i++){
        retVal = retVal * base;
    }
    return retVal;
}

int* library::combineIntArrays(int* X, int m, int* Y, int n){
    //int m = sizeof(a1);
    //int n = sizeof(a2);

    int retVal[m+n];

    for (int i = 0; i < (m + n); i++){
        if(i < m){
            retVal[i] = X[i];
        }
        else{
            retVal[i] = Y[i-m];
        }
    }

    return retVal;
}