#include <iostream>
using namespace std;

int* getPointer() {
    int x = 10;
    return &x; // return address of local variable
}

int main() {
    int var = 10;

    // declare pointer and store address of x: data_type* name;
    int* ptr = &var; // * dereference operator; & adressof operator
                     // dereferencing: 通过地址拿到值

    // print value and address
    cout << "Value of var: " << var << endl;
    cout << "Address of var: " << &var << endl;
    cout << "Value stored in pointer ptr: " << ptr << endl;
    cout << "Value pointed to by ptr: " << *ptr << endl;

    // Example of modifying address
    int a = 20;
    ptr = &a;
    cout << "Modified address: " << ptr << endl;
    cout << "Modified value: " << *ptr << endl;

    // size of pointers: only depends on OS and CPU architecture: 8 bytes for a 64-bit system; 4 bytes for a 32-bit system
    cout << "Size of pointer: " << sizeof(ptr) << endl;

    // 4 special types of pointers
    // 1. wild pointers: dereferencing may lead to errors such as segmentation faults
    int *ptr1;
    // 2. NULL pointer: point to NULL, initialize when you don't want it to point to any object
    int *ptr2 = NULL;
    // 3. void pointer: can hold the address of any data type, cannot be dereference directly -> must first be explicitly typecast to appropriate pointer type
    void* ptr3 = &a;
    // Error: cannot dereference void pointer
    // cout << *ptr3;
    cout << "Value pointed by void pointer: " << *(static_cast<int*>(ptr)) << endl;
    // 4. dangling pointer: refering to memory which has already been freed or is no longer valid(local variable has gone out of scope; dynamically allocated memory is deallocated using delete)
    // dereferencing a dangling pointer leads to undefined behavior
    int* ptr4 = getPointer();
    // undefined behavior
    // cout << *ptr4 << endl;

    // Double pointer(Pointer to pointer)
    int* ptr5 = &var;
    int** ptr6 = &ptr5;
    cout << *ptr5 << endl;
    cout << **ptr6 << endl;

    return 0;
}