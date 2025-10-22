// Interview question 1: predict the output
// Assume that unsigned int takes 4 bytes and long int takes 8 bytes
#include <stdio.h>

struct test {
    // Unsigned integer member x
    unsigned int x;
    // Bit-field member y with 33 bits
    long int y : 33; // needs 8-byte alignment
    // Unsigned integer member z
    unsigned int z;
};

int main()
{
    printf("%lu", sizeof(struct test));

    return 0;
}