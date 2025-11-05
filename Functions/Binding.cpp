// when a function is called in the code, binding decides which function gets executed based on the context, such as object type/function signature
// early binding: happens during compilation, faster because everything is decided early
// late binding: happens with virtual functions where the exact function to call is decided at runtime, depending on the actual object type
#include <iostream>
using namespace std;

class base
{
  public:
    virtual void print()
    {
        cout << "print base class\n";
    }

    void show()
    {
        cout << "show base class\n";
    }
};

class derived : public base
{
  public:
    // we have created virtual function print() in base class, and it's being overridden in derived class
    // then we don't need a virtual keyword here, print() is automatically considered a virtual function
    void print()
    {
        cout << "print derived class\n";
    }

    void show()
    {
        cout << "show derived class\n";
    }
};

int main()
{
    base *bptr;
    derived d;
    bptr = &d;

    // Virtual function, binded at runtime, when the actual object type is derived
    bptr->print();

    // Non-virtual function, binded at compile time
    bptr->show();
    return 0;
}

/* How does the compiler perform runtime resolution?
the compiler maintains two things:
1. vtable: a table of function pointers, maintained per class
2. vptr: a pointer to vtable, maintained per object instance

the compiler adds additional code at two places to maintain and use vptr:
1. code in every constructor. this code sets the vptr of the object being created and sets vptr to point to the vtable of the class
2. code with polymorphism function call. 多态function被called -> compiler inserts code用base class pointer/reference找vptr -> access vptr指向的vtable -> 可以access vtable里的function address
e.g. bptr指向derived class -> derived class vptr -> derived class vtable -> derived class print()
*/