// undefined behavior: use a pointer of base class type with no virtual destructor to delete a derived class object

#include <iostream>
using namespace std;

class base0 {
    public:
        base0() { cout << "base0 constructor called" << endl; }
        ~base0() { cout << "base0 destructor called" << endl; }
};

class base1 : public base0 {
    public:
        base1() { cout << "base1 constructor called" << endl; }
        ~base1() { cout << "base1 destructor called" << endl; }
};

class derived1 : public base1 {
    public:
        derived1() { cout << "derived1 constructor called" << endl; }
        ~derived1() { cout << "derived1 destructor called" << endl; }
};

class base2 : public base0 {
    public:
        base2() { cout << "base2 constructor called" << endl; }
        virtual ~base2() { cout << "base2 destructor called" << endl; } 
};

class derived2 : public base2 {
    public:
        derived2() { cout << "derived2 constructor called" << endl; }
        ~derived2() { cout << "derived2 destructor called" << endl; }
};

int main() {
    derived1* d1 = new derived1();
    base1* b1 = d1;
    delete b1; // will only call the destructor of base1(b1's own type), and base0(b1's superclass)
    getchar();

    cout << "With virtual desctructor:\n";
    derived2* d2 = new derived2();
    base2* b2 = d2;
    delete b2; // will also call the destructor of derived2, as base2 has a virtual destructor
    getchar();

    return 0;
}