#define _GNU_SOURCE
#include "mallocfree.h"
#include <dlfcn.h>
#include <stdio.h>

int main(void){
    //printf("here");
    void* (*mallocp)(size_t size);

    void* lib = dlopen("./mallocfree.so", RTLD_LAZY);

    mallocp = dlsym(lib, "malloc");
    //printf("here");
    int* x = (int*) mallocp(sizeof(int));
    *x = 5;

    printf("\nHere's your %d bytes of memory:\nX = %d\n", (int)sizeof(int), *x);
    //free(x);
    void (*freep)(void* ptr);

    freep = dlsym(lib, "free");
    freep(x);

    // print out the space_allocated variable from the library
    int space_allocated = *(int*)dlsym(lib, "SPACE_ALLOCATED");
    printf("\nSpace allocated: %d bytes (should be 0)\n", space_allocated);

    dlclose(lib);

    return 0;
}