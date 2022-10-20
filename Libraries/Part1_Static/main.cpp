#include "library.h"
#include <cstdio>

int main(){
    int output = library::addFive(-5);
    printf("Output: %d\n", output);
    //cout << library::addFive(output) << endl;
    return 0;
}