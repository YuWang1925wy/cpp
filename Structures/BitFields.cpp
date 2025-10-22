// specify the size in bits of the structure and union members, when we know the value of a field will never exceed a limit

#include <stdio.h>

// Space optimized representation of the date
struct date {
    // d has value between 0 and 31, so 5 bits are sufficient
    signed int d : 5; // signed int default is 4 bytes, so without bit fields, struct date should have 12 bytes

    // m has value between 0 and 15, so 4 bits are sufficient
    signed int m : 4;

    int y;
};

int main()
{
    printf("Size of date is %lu bytes\n", sizeof(struct date)); // all bit-fields of the same type share one 4-byte word
    struct date dt = {  31, 12, 2014 };
    printf("Date is %d/%d/%d", dt.d, dt.m, dt.y); // -> Date is -1/-4/2014 because we used signed int, d = 31 was stored as 11111
                                                  // MSB(most significant bit) is 1, so we need to calculate the complement(00000) and add 1(00001)
                                                  // so we output -1
    return 0;
}