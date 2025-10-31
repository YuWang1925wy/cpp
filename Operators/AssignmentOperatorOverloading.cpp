// assignment operator(=) are predefined to operate only on built-in data types
// the compiler automatically provides a default assignment operator for classes, which perform shallow copy of each member of the class from one object to another

// = overloading is binary operator overloading
// only a non-static member function should be used to overload =

// perform assignment operator overloading when we need a deep copy
#include <iostream>
using namespace std;

class GfG1 {
public:
    int* arr;
    int _size;
    GfG1(int size = 3) {
        arr = new int[size];
        _size = size;
    }
    
    // Deleting dynamic resources
    ~GfG1() {
        delete arr;
    }
};

class GfG2 {
    public:
        int* arr;
        int _size;
        GfG2(int size = 3) {
            arr = new int[size];
            _size = size;
        }
        
        // Overloaded assignment operator
        GfG2& operator=(const GfG2& c) {
            
            // self assignment check
            if (this != &c) {
                
                // Allocate new block
                int* temp = arr;
                arr = new(nothrow) int[c._size];
                
                // If allocation fails
                if (arr == nullptr) {
                    arr = temp;
                }
                else {
                    
                    // Deallocate current block
                    delete [] temp;
                    
                    // Copy data
                    _size = c._size;
                    memmove(arr, c.arr, _size * sizeof(int));
                }
            }
            return *this;
        }
        
        // Deleting dynamic resources
        ~GfG2() {
            delete arr;
        }
};

int main() {
    /* below code will throw errer at run time: double free errors
    GfG1 c1,c2;
    c1 = c2; // shallow copy(no = overloading): only the memory address is copied, not the actual data
    
    cout << c1.arr << endl;
    cout << c2.arr;
    */

    GfG2 c3,c4;
    
    // Initialize c2.arr with some values
    for (int i = 0; i < c4._size; i++) {
        c4.arr[i] = i + 10;
    }
    
    // Copying c2 object to c1, = overloading and perform a deep copy
    c3 = c4;
    
    // Print the pointers to the allocated memory
    cout << "c3.arr: " << c3.arr << endl;
    cout << "c4.arr: " << c4.arr << endl;
    
    return 0;
}