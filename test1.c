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

int main(void)
{
    char *l=(char*)malloc(SIZE);

    if (l)
	print_memory(l,SIZE);
    else
	puts("unable to malloc memory");

    return 0;
}
