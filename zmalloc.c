#define _GNU_SOURCE	1
#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>
 
void *malloc(size_t size){
    return calloc(1,size);
}

void free(void *ptr){
    char* ch_ptr = ptr;
    free(ptr);
}
