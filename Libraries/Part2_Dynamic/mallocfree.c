#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

// global variable to indicate whether space is allocated or not
int space_allocated = 0;

void* malloc(size_t size){
    // function pointer referring to a malloc function
    void* (*mallocp)(size_t size);

    // loads the malloc function from the library
    mallocp = dlsym(RTLD_NEXT, "malloc");

    // calls the real malloc function
    char* ptr = mallocp(size);

    space_allocated += size;
    printf("\nAllocated %zu bytes, total %d bytes\n", size, space_allocated);
    
    printf("Malloc(%zu) = %p\n", size, ptr);
    return ptr;
}

void free(void* ptr){
    // function pointer referring to a free function
    void (*freep)(void* ptr);

    // loads the free function from the library
    freep = dlsym(RTLD_NEXT, "free");

    space_allocated -= sizeof(ptr);
    printf("\nFreed %lu bytes, total %d bytes\n", sizeof(ptr), space_allocated);

    printf("Freeing memory: %p\n", ptr);
    // calls the real free function
    freep(ptr);                             
}