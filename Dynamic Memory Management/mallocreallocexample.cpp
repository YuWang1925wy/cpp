#include <stdio.h>
#include <stdlib.h>

int main() {
    
    // Initially allocate memory for 5 integers
    int *ptr = (int *)malloc(5 * sizeof(int));
    
    // Check if allocation was successful
    if (ptr == NULL) {
        printf("Memory Allocation Failed\n");
        exit(0);
    }
    
    // Now, we need to store 8 elements so reallocate to store 8 integers
    ptr = (int *)realloc(ptr, 8 * sizeof(int)); 
    
    /* actually, if realloc() fails and returns NULL, the original memory block is not freed,
    so should not overwrite the original pointer unitl successfully allocated a new block. Below is safer than above line:
    
    int *temp = (int*)realloc(ptr, 8 * sizeof(int));
    if (temp == NULL)
        printf("Memory Reallocation Failed.\n")
    else
        ptr = temp;
    */

    // Check if reallocation was successful
    if (ptr == NULL) {
        printf("Memory Reallocation Failed\n");
        exit(0);
    }
    
    // Assume we only use 5 elements now
    for (int i = 0; i < 5; i++) {
        ptr[i] = (i + 1) * 10;
    }
    
    // Shrink the array back to 5 elements
    ptr = (int *)realloc(ptr, 5 * sizeof(int));
    
    // Check if shrinking was successful
    if (ptr == NULL) {
        printf("Memory Reallocation Failed\n");
        exit(0);
    }
    
    for (int i = 0; i < 5; i++)
        printf("%d ", ptr[i]);
    
    // Finally, free the memory when done
    free(ptr);
    
    return 0;
}