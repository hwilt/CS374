#include <dlfcn.h>
#include <stddef.h>

void* malloc(size_t size) {
    void*(*mymalloc)(size_t) = (void* (*)(size_t)) dlsym(RTLD_NEXT, "malloc");
}


//todo: do the same for free, void function that accepts a void* parameter and returns a void* 