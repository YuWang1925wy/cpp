#include <stdio.h>
#include <stdlib.h>

void foo(int* string)
{
    if (string == NULL) {
        printf("NULL Pointer Passed");
        return;
    }
    printf("Non-Null Pointer Passed");
}

int main()
{
    int* ptr = NULL; // type ptr_name = NULL;
    int ptr2 = NULL; // or type ptr_name = 0;

    // derefencing only if the pointer have any value(error handling in pointer-related code)
    if (ptr == NULL) {
        printf("Pointer does not point to anything\n");
    }
    else {
        printf("Value pointed by pointer: %d", *ptr);
    }

    // malloc() returns NULL pointer when the memory allocation failed
    int* ptr3 = (int*)malloc(5 * sizeof(int));

    // checking if the memory allocation is successful
    if (!ptr) {
        printf("Memory Allocation Failed\n");
        // exit(0);
    }

    // pass NULL to a function
    foo(NULL);

    return 0;
}