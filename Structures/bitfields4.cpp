// Interview question 3: predict the output
#include <stdio.h>

union test {
    // Bit-field member x with 3 bits
    unsigned int x : 3;
    // Bit-field member y with 3 bits
    unsigned int y : 3;
    // Regular integer member z
    int z;
};

int main()
{
    
    union test t;
    t.x = 5;
    t.y = 4;
    t.z = 2; // In a union, only the most recently written member is the “active” one
    
    printf("t.x = %d, t.y = %d, t.z = %d", t.x, t.y, t.z);

    return 0;
}