/*
       ptr2   -   ptr1   -   variable
value  addr1    addr_var     value
addr   addr2    addr1        addr_var

ptr2 is the pointer to pointer(double pointer)
*/

#include <iostream>
using namespace std;

int main()
{
    int variable = 169;
    int* pointer1;

    // double pointer to store the address of pointer1
    // syntax: data_type** double_ptr_name = &normal_ptr_name;
    int** pointer2;

    pointer1 = &variable;
    pointer2 = &pointer1;

    cout << "Value of variable : " << variable << "\n";
    cout << "Value of variable using single pointer : " << *pointer1 << "\n";
    cout << "Value of variable using double pointer : " << **pointer2 << "\n";
    cout << "Size of normal Pointer: " << sizeof(pointer1) << "\n"; // all pointers are 8 bytes on a 64-bit machine
    cout << "Size of double Pointer: " << sizeof(pointer2) << "\n"; // since they need to storea 64-bit address
    
    return 0;
}