// malloc() doesn't initialize the allocated memory. if read from the allocated memory without first initializing it, will invoke undefined behavior
// calloc() initializes every byte to 0
// both return NULL if allocation fails
#include <stdio.h>
#include <stdlib.h>

int main(){
    int* allocate_with_malloc = (int*)malloc(5 * sizeof(int)); // malloc: 1 argument, number of bytes
    int* allocate_with_calloc = (int*)calloc(5, sizeof(int)); // calloc: 2 arguments, number of blocks to be allocated, size of each block

    printf("Values of allocate_with_calloc: ");
    for (size_t i=0; i < 5; i++) {
        printf("%d ", allocate_with_calloc[i]);
    }
    putchar('\n');

    printf("Values of allocate_with_malloc: ");
    for (size_t i=0; i < 5; i++) {
        printf("%d ", allocate_with_malloc[i]);
    }
    putchar('\n');

    int* failed_malloc = (int*)malloc(1000000000000); // requests 1 terabyte of dynamic memory, unavailable
    if (failed_malloc == NULL) {
        printf("The allocation failed, failed_malloc = %p", (void*)failed_malloc);
    }

    free(allocate_with_calloc);
    free(allocate_with_malloc);

}