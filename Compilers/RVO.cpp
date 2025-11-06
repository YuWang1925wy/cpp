// copy elision(or copy omission): a compiler optimization method, prevents objects from being duplicated/copied
// RVO: return value optimization, a technique that gives the compiler some additional power to terminate the temporary object created

#include <iostream>
using namespace std;

class GfG{
    public:
        GfG() { cout << "Default constructor called" << endl; }
        GfG(const GfG&){
            cout << "Copy constructor called" << endl;
        }
};

GfG func(){
    return GfG(); // RVO: The returned prvalue is constructed directly in the caller’s storage; 
                  // no local temporary is materialized and no copy/move constructor is invoked
}

int main(){
    GfG g = func(); // the compiler will decide what to print, could be default constructor once + copy constructor none, once, or twice
    getchar();
    return 0;
}