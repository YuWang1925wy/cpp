// compiler creates a default copy constructor if there is no user-defined constructor
// default copy constructors do shallow copy, and work for basic types, but do not work for dynamic allocated memory
// -> custom copy constructors are needed if a class has pointers or runtime resources(e.g. dynamic memory, file handles, network connections)

#include <iostream>
using namespace std;

// class A has a default copy constructor created by compiler
// class A and class B only has basic type data members, so the copy constructors just copy the actual value, shallow copy is not a problem here
class A
{
  public:
    int x;
};

class B
{
  public:
    int x;
    B(){}; // we defined a copy constructor for class B, so the implicit default constructor will not be provided, so we have to manually define it

    // Copy Constructor: className(className &objName){}
    B(B &obj)
    {
        x = obj.x;
        cout << "Copy constructor of class B called." << endl;
    }
};

class C
{
  public:
    int* p;
    C(int* q) { p = q; }
};

int main()
{
    A a1;
    a1.x = 10;
    cout << "a1.x = " << a1.x << endl;

    // default copy constructor of class A is called
    A a2(a1);
    cout << "a2.x = " << a2.x << endl;

    // demo for user-defined copy constructor
    B b1;
    b1.x = 20;
    cout << "b1.x = " << b1.x << endl;
    B b2(b1);
    cout << "b2.x = " << b2.x << endl;

    // example of shallow copy(only pointer values are copied, so when the value at the pointed address changes, both objects change)
    int var = 1;
    int* ptr = &var;
    C c1(ptr);
    C c2(c1);
    cout << "c1.p = " << c1.p << endl;
    cout << "c2.p = " << c2.p << endl;
    var = 2;
    cout << "var = " << var << endl;
    cout << "c1.p = " << *(c1.p) << endl;
    cout << "c2.p = " << *(c2.p) << endl;
    return 0;
}