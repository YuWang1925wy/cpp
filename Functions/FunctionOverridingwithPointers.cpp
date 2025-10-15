#include <iostream>
using namespace std;

class Base{
    public:
        virtual void display() {
            cout << "Display from Base class" << endl;
        }
};

class Derived: public Base{
    public:
        void display() override {
            cout << "Display from derived class" << endl;
        }
};

int main() {
    Base * basePtr;
    Derived derivedObj;
    basePtr = &derivedObj; // basePtr pointing to Derived type object(can change to Base type, or types derived from Base)
    basePtr->display(); // the function call is resolved at runtime based on the type of the object being pointed to, not the type of the pointer
    return 0;
}