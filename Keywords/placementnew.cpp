// normal new operator: 1. allocates memory 2. constructs an object in allocated memory
// placement new operator(variation of new): seperate the two things above
// we can pass a preallocated memory, and construct an object in passed memory(known address, already allocated memory)
// use it when it's required the re-construct an object multiple times, so that it's faster not to re-allocate all the time

#include<iostream>
using namespace std;

int main()
{
    // buffer on stack: unsigned char is a byte type(store bytes, not human-readable numbers), size is 1 byte
    unsigned char buf[sizeof(int)*2];
    cout << "buf: " << buf << endl;
    cout << "&buf: " << &buf << endl; // address of buf is used for later memory allocation
                                      // since we initialize buf to have the size for 2 integers, we know this address has enough memory
    cout << "buf addr: " << static_cast<void*>(buf) << "\n";

    // placement new in buf: data_type* var_name = new (address) data_type(constructor_arguments);
    // it returns a pointer to the newly constructed object
    int *pInt = new (buf) int(3);

    int *qInt = new (buf + sizeof (int)) int(5);
    int *pBuf = (int*)(buf+0) ;
    int *qBuf = (int*) (buf + sizeof(int));
    cout << "Buff Addr             Int Addr" << endl;
    cout << pBuf <<"             " << pInt << endl;
    cout << qBuf <<"             " << qInt << endl;
    cout << "------------------------------" << endl;
    cout << "1st Int             2nd Int" << endl;
    cout << *pBuf << "                         " << *qBuf << endl;

    /*Do not delete these pointers. With placement new, you don’t own heap storage. If the type had a destructor, call it manually:
    pInt->~int();  // trivial for int, so not needed
    qInt->~int();
    */

    return 0;
}