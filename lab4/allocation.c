#include <stdio.h>
#include <stdlib.h>

int main() {
int *forheap;

forheap = (int *)malloc(sizeof(int));
*forheap = 30;

printf("Address of pointer (Stack): %p\n", (void*)&forheap);
printf("Address of data (Heap): %p\n", (void*) forheap);
printf("Value stored: %d\n", *forheap);
printf("Value stored: %d\n", *forheap);
return 0;

}
