#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

// global variable to indicate whether space is allocated or not
int SPACE_ALLOCATED = 0;
/*
struct Node
{
    void* addr;
    int size;
    struct Node* next;
};

struct Node* head = NULL;

void insert(void* addr, int size){
    struct Node* ptr = head;
    while(ptr != NULL){
        ptr = ptr->next;
    }
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->addr = addr;
    new_node->size = size;
    ptr->next = new_node;
}

int lookup(void* addr){
    int size;
    struct Node* temp = head;
    while (temp != NULL){
        if (temp->addr == addr){
            size = temp->size;
            return size;
        }
        temp = temp->next;
    }
    return -1;
}

void delete(void* addr){
    struct Node* temp = head;
    struct Node* prev = NULL;
    if (temp != NULL && temp->addr == addr){
        head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->addr != addr){
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL){
        return;
    }
    prev->next = temp->next;
    free(temp);
}*/

void* malloc(size_t size){
    // function pointer referring to a malloc function
    void* (*mallocp)(size_t size);

    // loads the malloc function from the library
    mallocp = dlsym(RTLD_NEXT, "malloc");

    // calls the real malloc function
    char* ptr = mallocp(size);

    
    //insert(ptr, size);
    SPACE_ALLOCATED += 1;
    printf("\nAllocated %d bytes, total %d bytes\n", (int)size, SPACE_ALLOCATED);
    
    printf("Malloc(%d) = %p\n", (int)size, ptr);
    return ptr;
}

void free(void* ptr){
    // function pointer referring to a free function
    void (*freep)(void* ptr);

    // loads the free function from the library
    freep = dlsym(RTLD_NEXT, "free");

    /*int size = lookup(ptr);
    if (size == -1){
        printf("Error: free() called on an address that was not allocated\n");
        return;
    }
    else{
        delete(ptr);
        SPACE_ALLOCATED -= size;
        printf("\nFreed %d bytes, total %d bytes\n", (int)sizeof(ptr), SPACE_ALLOCATED);

        printf("Freeing memory: %p\n", ptr);
        // calls the real free function
        freep(ptr); 
    }*/
    SPACE_ALLOCATED -= 1;
    printf("\nFreeing memory: %p\n", ptr);
    printf("Total %d bytes\n", SPACE_ALLOCATED);

    
    // calls the real free function
    freep(ptr);
                                
}