// Compile time: stack memory is automatically allocated for variables, fixed size
// Run time: new allows manual allocation on the heap; delete allows manual deallocation on the heap
// useful when the size of required memory isn't known at compile time

// the new operator allocates memory from the Free Store(a portion of the heap)
// enough memory -> new initializes the memory with a default value based on its type and return the address of the allocated memory
#include <iostream>
#include <memory>
using namespace std;

int main() {

    int *nptr;
    cout << *nptr << endl; // initializes the memory with a default value based on its type
    
    nptr = new int(6);
    cout << *nptr << endl;

    // Print the address of memory block
    cout << "Memory address: " << nptr << endl;

    // allocate block(array) of memory
    int *nptr2;
    nptr2 = new int[5]{1,2,3,4,5}; // syntax: new data_type[n];
    for (int i = 0; i < 5; i++) cout << nptr2[i] << " ";

    /* not enough memory on the heap -> will throw an exception of type std::bad_alloc
    int *p = new (nothrow) int; // this one won't throw the exception
    if (!p) {                   // good to check if use nothrow
        cout << "Memory allocation failed\n";
    }
    */

    return 0;
}