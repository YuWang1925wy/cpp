#include <iostream>
using namespace std;

int main() {

    // 1. increment or decrement pointers
    // address +/- 1 * size of the data type
    int arr[5] = {2, 4, 8, 12, 16};
    int* ptr = arr;

    cout << "Size of int: " << sizeof(int) << endl;

    cout << "Before Increment: " << ptr << endl << "*ptr: " << *ptr << endl;
    ptr++;
    cout << "After Increment: " << ptr << endl << "*ptr: " << *ptr << endl;

    cout << "Before Decrement: " << ptr << endl << "*ptr: " << *ptr << endl;
    ptr--;
    cout << "After Decrement: " << ptr << endl << "*ptr: " << *ptr << endl;

    // 2. add/subtract integer values to pointers
    // address +/- int * size of data type
    ptr += 2;
    cout << "After adding 2: " << ptr << endl << "*ptr: " << *ptr << endl;

    // 3. pointer - pointer of the same data type
    int* ptr2 = &arr[4];
    cout << "ptr2 - ptr = " << ptr2 - ptr << endl; // -> 2 as ptr is pointing to arr[2] right now

    // 4. comparison of pointers(>, <, >=, <=, ==, !=)
    // checking if two pointers are pointing to the same memory location
    cout << "ptr == ptr2 ? " << (ptr == ptr2) << endl;
    cout << "ptr <= ptr2 ? " << (ptr <= ptr2) << endl;
    ptr += 2;
    cout << "ptr == ptr2 after ptr+=2 ? " << (ptr == ptr2) << endl;
    cout << "ptr == NULL ? " << (ptr == NULL) << endl; // checking whether ptr points to some memory address, helps to control errors like segmentation faults


    return 0;
}