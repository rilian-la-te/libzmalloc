#define _GNU_SOURCE	1
#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>
 
void *malloc(size_t size){
    return calloc(1,size);
}

void free(void *ptr){
    char* casted_ptr = (char*)ptr;
    size_t byte_count = sizeof(*casted_ptr);
    FILE *fp;
    fp = fopen("/dev/urandom", "r");
    fread(casted_ptr, 1, byte_count, fp);
    fclose(fp);
    free(ptr);
}
