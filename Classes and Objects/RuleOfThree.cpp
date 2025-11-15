// rule of three: if a class defines one(or more) of the following, it should explicitly define all three
// desctructor
// copy constructor
// copy assignment operator

#include <algorithm>  // for std::copy
#include <iostream>
using namespace std;

class Array {
    private:
        int size;
        int* vals;

    public:
        ~Array();
        Array(int s, int* v);

        void getter() {
            for (int i = 0; i < size; i++)
            cout << vals[i] << endl;
        }
};

Array::~Array() {
    delete[] vals;
    vals = nullptr;
}

Array::Array(int s, int* v) {
    size = s;
    vals  = new int[size];
    std::copy(v, v + size, vals);
}

int main() {
    int vals[4] = { 11, 22, 33, 44 };
    Array a1(4, vals);
    a1.getter();
    

    /* the line below will throw error at runtime
    Array a2(a1);
    
    reason: no copy constructor is explicitly defined, so the program will call the default copy constructor,
            which perform shallow copy, so when the program goes out of scope, the desctructor will call on the 
            same memory twice
    */
   
    return 0;
}

// deep copy can avoid double freeing memory

