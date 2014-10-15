#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SIZE 100

print_memory(char *c,int size)
{
    int i;
    for(i=0;i<size;i++){
        printf(" %.2x",*(c+i));
	if ((i+1) % 20 == 0) puts("");
    }
    puts("");
}


int main()
{
    char *c;

    c=malloc(SIZE*sizeof(char));
    memset(c,0x33,SIZE*sizeof(char));
    puts("old memory content:");
    print_memory(c,SIZE);

    free(c);
    c=malloc(SIZE*sizeof(char));

    puts("new memory content:");
    print_memory(c,SIZE);    

    return 0;
}

