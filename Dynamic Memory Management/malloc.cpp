#include <cstdlib>   // std::malloc, std::free
#include <cstdio>    // std::printf
#include <new>       // operator new
#include <iostream>
using namespace std;

struct Test { 
    Test() { cout << "Constructor\n"; }
    ~Test() { cout << "Destructor\n"; }
};

int main() {
    // T var = malloc(number of bytes to allocate)
    int* p1 = static_cast<int*>(std::malloc(4 * sizeof(int))); // malloc() returns void *, so we need to use static_cast for type conversion
    int* p2 = static_cast<int*>(std::malloc(sizeof(int[4])));  // static_cast is a compile-time cast
    int* p3 = static_cast<int*>(std::malloc(4 * sizeof *p3));

    if (p1) {
        for (int n = 0; n < 4; ++n) p1[n] = n * n;
        for (int n = 0; n < 4; ++n) std::printf("p1[%d] == %d\n", n, p1[n]);
    }

    std::free(p1); // release the memory
    std::free(p2);
    std::free(p3);

    // malloc: raw memory only
    Test* p4 = (Test*)std::malloc(sizeof(Test));
    // No constructor called
    std::free(p4);  // No destructor called

    // new: free store + constructor
    Test* p5 = new Test;   // calls constructor
    delete p5;  

    return 0;
}

/*  Differences between malloc() and new
1. new calls constructors, malloc() does not
2. new is an operator, malloc() is a function
3. new returns exact data type, malloc() returns void*
4. on failure of memory allocation, new throws bad_alloc exception, malloc() returns NULL
5. for new, memory is allocated from free store, malloc() memory allocation is done from heap
    - Free store: concept in C++, region of memory managed by C++ memory manager where objects created with new live
    - Heap: region of memory managed by the OS and runtime, used for dynamic memory allocation
6. new doesn't allow to change the size of the buffer, alloc() allows using realloc()
*/
