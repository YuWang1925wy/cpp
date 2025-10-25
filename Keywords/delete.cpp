/* syntax
delete ptr;
delete[] ptr;

frees the pointed-to object(value or memory block), but the pointer variable still holds a dangling value(pointer is not destroyed)
Using or deleting it again is undefined behavior

the delete operator has void return type
*/

#include <iostream>
using namespace std;

int main() {
    int *ptr = NULL;

    // Request memory for integer variable using new operator
    ptr = new int(10);
    if (!ptr) {
        cout << "allocation of memory failed";
        exit(0);
    }

    cout << "Value of *p: " << *ptr << endl;
    cout << "Address of the memory: " << ptr << endl;

    // Free the value once it is used
    delete ptr;
    cout << "Value of *p after delete: " << *ptr << endl;
    cout << "*p point to NULL? " << (ptr == nullptr) << endl;
    cout << "Address of the memory after delete: " << ptr << endl;
    
    // Allocate an array
    ptr = new int[3];
    ptr[2] = 11;
    ptr[1] = 22;
    ptr[0] = 33;
    cout << "Array: ";
    for (int i = 0; i < 3; i++)
        cout << ptr[i] << " ";

    // Deallocate when done
    delete[] ptr;
    cout << endl << "After delete the array: ";
    for (int i = 0; i < 3; i++)
        cout << ptr[i] << " ";
    
    return 0;
}