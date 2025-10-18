// every function has an address like all other variables in the program
// the name of a function can be used to find the address of the function
// we can get the address of a function by writing the function's name without parentheses

#include<stdio.h>

int add(int a, int b) {
    return a + b;
}

int main(void)
{
    // syntax: return_type (*pointer_name)(parameter_types)
    // the parenthesis around pointer_name is necessay: int* fun(int, int); is function declaration with the return type of int* and name fun
    int (*fptr)(int, int);
    // Initialization: assign to add()
    fptr = &add;
    /* below initialization works too, as function name itself behaves like a constant function pointer
    fptr = add;
    */
    printf("%d\n", fptr(10, 5));

    /* Restrictions(because function pointers point to the memory address of a function in the code segment i.e. point to the code):
    1. requires the exact function signature(can point to different functions with matching signatures, see example 3)
    2. cannot perform arithmetic operations like increment or decrement
    fptr++; -> will cause error
    3. supports array-like functionality for tables of function pointers(see example 3)
    */

    printf("address of function main() is :%p\n", main);
    return 0;
}