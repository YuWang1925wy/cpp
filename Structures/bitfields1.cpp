// 1. can use bit fields for forced alignment in structures
// 2. pointers cannot point to bit field members as they may not start at a byte boundary
#include <stdio.h>

// A structure without forced alignment
struct test1 {
    unsigned int x : 5;
    unsigned int y : 8; // 13 bits in total, <= 2 bytes
    unsigned int z;
    /* 3. array of bit fields is not allowed
    unsigned int x[10] : 5; -> will cause error
    */
};

// A structure with forced alignment
struct test2 {
    unsigned int x : 5;
    unsigned int : 0; // force alignment to the next memory boundary(y starts at an address that is a multiple of 4 if it's 4-byte boundary)
    unsigned int y : 8;
};

int main()
{
    printf("Size of test1 is %lu bytes\n", sizeof(struct test1));
    printf("Size of test2 is %lu bytes\n", sizeof(struct test2));

    struct test1 t;
    /* the line below will cause error, as x is a bit field member
    printf("Address of t.x is %p", &t.x);
    */

    // The below line works fine as z is not a bit field member
    printf("Address of t.z is %p\n", &t.z);

    // Example of what happens when out-of-range value is assigned to bit field member
    t.x = 33; // will cause warning at compile time
    printf("t.x = %d\n", t.x);

    return 0;
}