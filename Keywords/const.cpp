// declared as unchangable(read-only): variables, objects, pointers, function parameters, return values, class methods

#include <iostream>
using namespace std;

// example for const arguments in functions
void printfunc(int *ptr)
{
    cout << "Value: " << *ptr << endl;
    cout << "Address of value: " << ptr << endl;
    cout << "Address of ptr: " << &ptr << endl;
}

// example for const member functions
class Test {
    int value;

    public:
        Test(int v = 0){ // constructor
            value = v;
            cout << "object initialized as " << v << endl;
        }

        // const member function syntax: return_type foo() const {...}
        // while ordinary function syntax: const return_type foo(){...}
        int getValue() const { // will get compiler error if we add a line like value = 100; in this function
            return value;
        }

        void setValue(int val){
            value = val;
        }

};

// example for const function parameters and return type
void foo(const int y){ // can't change the value of y in this function
    cout << y << endl;
}

void foo1(int y){
    y = 5;
    cout << y << endl;
}

void foo2(int& y){
    y = 5;
    cout << y << endl;
}

const int foo3(int y){
    y--;
    return y;
}

int main() {
    const int y = 10; // const variable must be initialized at the time of declaration
    /* below will throw error
    const int x;
    x = 10;
    */
    cout << "y = " << y << endl;

    // 1. pointer to const value
    int x1 = 8;
    char y1 = 'M';
    const int* i1 = &x1; // i1 points to a "const int" value, so this is a pointer to a const value(*i is the const value, but i is the pointer)
    const char* j1 = &y1;
    // can change the value of x1 and y1, can change the pointer to point to another address
    i1 = &y;
    x1 = 9;
    y1 = 'A';
    /* can't change the values through pointers, will throw error
    *i1 = 8;
    *j1 = 'B';
    */
    cout << "*i1 = " << *i1 << " *j1 = " << *j1 << endl;

    // 2. const pointer to non-const value
    int x2 = 5;
    int z2 = 6;
    char y2 = 'A';
    char p2 = 'B';
    int *const i2 = &x2; // i2 points to an "int", so this is a const pointer to a non-const value
    char* const j2 = &y2;
    *i2 = 10;
    *j2 = 'C';
    /* pointer variable is const type, so the address pointed by the pointer variables can't be change(const pointers can't point to another address)
    i2 = &z2;
    j2 = &p2;
    will throw error */
    cout << "*i2 = " << *i2 << " *j2 = " << *j2 << endl;
    cout << "i2 = " << i2 << " j2 = " << j2 << endl;

    // 3. const pointer to a const value
    int x3 = 1;
    const int* const i3 = &x3;
    x3 = 2; // we can't change the value with *i3 = ...; or i3 = &...; but still can use x3 = ... 
            // because const is applied to the pointer, not the value being pointed to
    cout << "*i3 = " << *i3 << endl;

    // 4. const arguments in functions
    const int* i4 = &x1;
    int* const j4 = &x1;
    /* below will throw error because we can't pass a const int* type to the function,
    which expects a non-const parameter
    printfunc(i4);
    */
    printfunc(j4); // passing a const pointer is fine, because another pointer is created, which also points to the same memory location
    cout << "Address of x1(value): " << j4 << endl;
    cout << "Address of j4: " << &j4 << endl;

    // 5. const member functions
    // const member functions can be called on const objects and non-const objects
    // const object can only call const member functions
    // const objects need to be initialized at the time of declaration
    Test t(20);
    t.setValue(2);
    cout << "t.getValue() = " << t.getValue() << endl;

    const Test t_const(1); // an object declared as const can not be modified, so can only invoke const member functions as these functions ensure not to modify the object
    /* below will throw error, because const object is invoking non-const function
    t_const.setValue();
    */
    cout << "t_const.getValue() = " << t_const.getValue() << endl;

    // 6. const function parameters and return type
    const int b = 2;
    foo1(b); // fine because we pass by value, a copy will be created
    // foo2(b); will throw error because the variable is passed by reference
    foo3(b); // fine because pass by value

    return 0;
}