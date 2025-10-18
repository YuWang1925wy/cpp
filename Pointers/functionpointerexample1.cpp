// Function pointer application 1: passing functions as arguments to other functions
// this allows you to specify which function to call at runtime
#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

// the parameter int (*op)(int, int) actually declare a function pointer
// that's why we can pass functions as arguments in main below
void calc(int a, int b, int (*op)(int, int)) { 
    printf("%d\n", op(a, b));
}

int main() {
    // Passing different functions to 'calc'
    calc(10, 5, add);
  	calc(10, 5, subtract);
    return 0;
}