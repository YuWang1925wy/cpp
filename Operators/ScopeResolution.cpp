#include <iostream>
using namespace std;

// Global x
int x = 3;

namespace N {
    int val = 10;
}

class A {
    public:
        void fun();
        static int x;
};

void A::fun() {
    cout << "class A fun() called." << endl; // Application 4: define class member function outside of the class
}
int A::x = 1; // Application 5: access class's static members

class Base {
    public:
        void func() {
            cout << "Base class func() called." << endl;
        }
    };
    
class Derived : public Base {
    public:
      
        void func() {
            cout << "Derived class func()" << endl;
        }
};

int main() {
  	
  	// Local x
    int x = 10;
  
    cout << "::x " << ::x << endl; // Application 1: access global variables
    cout << "x " << x << endl;

    cout << "2. Access variable inside a namespace: " << N::val << endl;

    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int>::iterator first = arr.begin(); // Application 3: iterator declaration
    cout << "*first " << *first << endl;

    A a;
    a.fun();
    cout << "A::x " << A::x << endl;

    Derived obj;
    obj.Base::func(); // Application 6: refer to base class member in derived class type object
    obj.func();

    return 0;
}

// scope resolution operator can't be overloaded