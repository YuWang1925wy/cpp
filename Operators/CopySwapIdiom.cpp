// use copy and swap to overload =
/* bad codes(normal overloaded =):
class GfG {
    int size;
    int* ptr;

    public:
    
    GfG(int s = 0) {
        size = s;
        ptr = (size < 0) ? new int[size] : nullptr;
    }

    GfG(const GfG& obj){
        size = obj.size;
        this->ptr = (size < 0) ? new int[size] : nullptr;
        copy(obj.ptr, obj.ptr + size, this->ptr)
    }

    GfG& operator=(const GfG& obj){
        
        if (this != &obj) { // bad reason 1: self allocation is very rare, so it's not relevant in most cases, will slow down the code

            delete [] this->ptr; // bad reason 2: leave the pointer dangling. If the memory is not allocated, and an exception is thrown, 
                                 // this->ptr will be left dangling
            this->ptr = new int[obj.size];
            this->size = obj.size;
            memmove(this->ptr, obj.ptr, this->size * sizeof(int));
        
        }
    }
    // bad reason 3: the core logic of the = overloading(copying the actual data) is already written in the copy constructor

    ~GfG() { delete [] ptr; }
};

// the first two drawbacks can be handled by adding additional checks, but it increases the size of the code
*/

// Copy and Swap Idiom solves the above drawbacks
#include <iostream>
using namespace std;

class GfG{
    int size;
    int* ptr;

    public:
    GfG(int s = 0) {
        size = s;
        ptr = (size > 0) ? new int[size] : nullptr;
    }

    GfG(const GfG& obj){
        size = obj.size;
        ptr = (size > 0) ? new int[size] : nullptr;
        copy(obj.ptr, obj.ptr + size, this->ptr);
    }

    friend void swap(GfG& obj1, GfG& ojb2) {
        swap(obj1.size, ojb2.size);
        swap(obj1.ptr, ojb2.ptr);
    }

    GfG& operator=(GfG obj){ // pass by value, a local is created by calling copy constructor; after this function the copy will be destroyed automatically
        swap(*this, obj);
        return *this;
    }

    ~GfG() { delete [] ptr; }

    // helpers for testing in main
    int& operator[](int i)       { return ptr[i]; }
    const int& operator[](int i) const { return ptr[i]; }
    int length() const { return size; }

    void print(const char* tag) const {
        cout << tag << " (size=" << size << "): ";
        for (int i = 0; i < size; ++i) cout << ptr[i] << ' ';
        cout << '\n';
    }
};

int main() {
    // Build original
    GfG g(5);
    for (int i = 0; i < g.length(); ++i) g[i] = i + 1;   // 1 2 3 4 5
    g.print("g");

    // 1) Copy constructor
    GfG g2 = g;             // deep copy
    g2.print("g2 (after copy)");
    g2[0] = 99;             // mutate copy
    g.print("g (should be unchanged)");   // verifies deep copy
    g2.print("g2 (mutated)");

    // 2) Copy assignment
    GfG g3(5);
    for (int i = 0; i < g3.length(); ++i) g3[i] = 7;     // 7 7 7 7 7
    g3.print("g3 (before = g)");
    g3 = g;                     // copy-assign
    g3.print("g3 (after = g)");
    g[1] = 42;                  // mutate source
    g.print("g (mutated)");
    g3.print("g3 (should be unchanged)");

    // 3) Self-assignment safety
    g3 = g3;                    // should be a no-op and safe
    g3.print("g3 (after self-assign)");

    return 0;

}

// advantages of copy swap idiom
// 1. no self-assignment check needed, as the parameter is passed by value
// as self-allocation is very rare, the overhead of copying in case of self-assignment should not be a problem
// 2. copy constructor is used before swapping, it does what we did manually in the bad code version
// 3. size of operator=() is smaller

