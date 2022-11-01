#include "library.h"
#include <algorithm>

int library::addFive(int number){
    return number + 5;
}

int* library::combineIntArrays(int* X, int m, int* Y, int n){
    //int m = sizeof(a1);
    //int n = sizeof(a2);

    static int retVal[m+n];

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