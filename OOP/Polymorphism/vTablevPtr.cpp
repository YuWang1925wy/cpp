// vTable: a table of function pointers, created by the compiler to support dynamic polymorphism
// whenever a class contains a virtual function, the compiler creates a vTable for that class
// each object of this class is provided a hidden pointer(vPtr) to this table
// one entry(row) for each virtual function, 1 vtable for 1 class; these entries are pointers to the most derived function that the current object should call
// vPtr: n objects(of class that has or inherits virtual functions), n vPtr

#include <iostream>
using namespace std;

class Base {
    public:
        virtual void func1(){
            cout << "Base func1" << endl;
        }

        virtual void func2(){
            cout << "Base func2" << endl;
        }

        virtual void func3(){
            cout << "Base func3" << endl;
        }
};

class Derived1 : public Base {
    void func1(){
        cout << "Derived1 func1" << endl;
    }
};

class Derived2 : public Base {
    void func2(){
        cout << "Derived2 func2" << endl;
    }
};

int main(){
    Base* ptr1 = new Base();
    Base* ptr2 = new Derived1();
    Base* ptr3 = new Derived2();

    ptr1->func1(); // Base func1
    ptr1->func2(); // Base func2
    ptr1->func3(); // Base func3
    ptr2->func1(); // Derived1 func1
    ptr2->func2(); // Base func2
    ptr2->func3(); // Base func3
    ptr3->func1(); // Base func1
    ptr3->func2(); // Derived2 func2
    ptr3->func3(); // Base func3

    delete ptr1;
    delete ptr2;
    delete ptr3;

    return 0;
}