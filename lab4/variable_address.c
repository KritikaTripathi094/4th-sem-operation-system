#include <stdio.h>
#include <stdlib.h>

int global_var = 150;
int bss_var;

int main() {
int local_var = 30;
static int local_static = 20;

int *heap_var = (int *)malloc(sizeof(int));
*heap_var = 500;

printf(".......Variable Addresses.......\n\n");
printf("global_var: %p (Data/BSS)\n", (void*)&global_var);
printf("bss_var: %p (Data/BSS)\n", (void*)&bss_var);
printf("local_var: %p (Stack)\n", (void*)&local_var);
printf("local_static: %p (Data/BSS)\n", (void*)&heap_var);
printf("heap_var ptr: %p (stack - pointer)\n", (void*)&heap_var);
printf("*heap_var: %p (Heap - data)\n", (void*)heap_var);

free(heap_var);
return 0;
}

