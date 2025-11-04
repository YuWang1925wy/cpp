// Runtime polymorphism(or late binding, dynamic polymorphism)
#include <iostream>
using namespace std;

class Base {
public:

    // Virtual function: with the virtual keyword, the compiler defers the decision(which function to invoke) to runtime
    // based on the actual type of the object being pointed to
    virtual void display() {
        cout << "Base class function" << endl; // to be overridden
    }
};

class Derived : public Base {
public:

    // Overriding the base class function
    void display() override {
        cout << "Derived class function" << endl;
    }
};

int main() {

    Base* basePtr;
    Derived derivedObj;
    basePtr = &derivedObj;
    
    // Calling the display function using base class pointer
    basePtr->display();
    return 0;
}