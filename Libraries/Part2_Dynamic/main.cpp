#include "mallocfree.h"

int main(void) {
    int* x = (int*) malloc(sizeof(int)); 
    *x = 5;
    printf("%d\n", *x);
    free(x);
    // print your counter value, which you can declare as a static int in this module, and increment/decrement in malloc/free
}