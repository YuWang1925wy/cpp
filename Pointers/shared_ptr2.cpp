// C++ program to illustrate the use of make_shared
#include <iostream>
#include <memory>
using namespace std;

int main()
{
    // Creating shared pointers using std::make_shared
    shared_ptr<int> shr_ptr1 = make_shared<int>(42);
    shared_ptr<int> shr_ptr2 = make_shared<int>(24);
    // Accessing the values using the dereference operator
    // (*)
    cout << "Value 1: " << *shr_ptr1 << endl;
    cout << "Value 2: " << *shr_ptr2 << endl;
    // Using the assignment operator (=) to share ownership
    shared_ptr<int> shr_ptr3 = shr_ptr1;
    // Checking if shared pointer 1 and shared pointer 3
    // point to the same object
    if (shr_ptr1 == shr_ptr3) {
        cout << "shared pointer 1 and shared pointer 3 "
                "point to the same object."
             << endl;
    }
    // Swapping the contents of shared pointer 2 and shared pointer 3
    shr_ptr2.swap(shr_ptr3);
    // Checking the values after the swap
    cout << "Value 2 (after swap): " << *shr_ptr2 << endl;
    cout << "Value 3 (after swap): " << *shr_ptr3 << endl;
    // Using logical operators to check if shared pointers are valid
    if (shr_ptr1 && shr_ptr2) {
        cout << "Both shared pointer 1 and shared pointer "
                "2 are valid."
             << endl;
    }
    // Resetting a shared pointer
    shr_ptr1.reset();
}