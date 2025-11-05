// Pure virtual function: a function in a base class with =0 and no function body, and must be overriden in derived classes
// Abstract class: a class with pure virtual function, can not be instantiated
#include <iostream>
using namespace std;

class Base
{
  public:
  
    // Pure virtual function
    virtual void display() = 0;

    // Pure virtual destructor: 1. declared with =0; 2. makes the class abstract; 
    // 3. ensures that when you delete a derived class object through a base class pointer, the derived desctructor runs first, followed by the base destructor
    virtual ~Base() = 0;
};

// Definition of pure virtual destructor
Base::~Base()
{
    cout << "Base destructor called" << endl;
}

class Derived : public Base
{
  public:
    void display() override
    {
        cout << "Derived class display" << endl;
    }

    ~Derived()
    {
        cout << "Derived destructor called" << endl;
    }
};

int main()
{
    Base *basePtr;
    Derived derivedObj;
    basePtr = &derivedObj;
    basePtr->display();
    return 0;
}