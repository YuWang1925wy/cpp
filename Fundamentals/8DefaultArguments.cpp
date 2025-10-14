#include <iostream>
using namespace std;

// default values much be in the declaration, not definition
void func(int x = 10); // declaration
void func(int x){ // definition
    cout << "Value: " << x << endl;
}
// default arguments cannot be modified in definition after they are specified in declaration

// default arguments should start from one arguments and all arguments to its right must be provided
void func2(int x, int y = 20); //valid
// void func(int x = 10, int y); invalid

// overloading functions with default arguments can't be ambiguious
// Valid
void f(int a = 10, int b = 20);
  
// Will throw error as the signature is same
// void f(int a = 22, int b = 2);
// Below will also throw error
// void f(int a);
// void f(int a, b);

// can define default values for the arguments of parameterized constructor
class A {
public:
    int data;

  	// Parameterized constructor with default values
    A(int x = 5) { data = x; }
};

// Function Overloading Example: a form of compile time polymorphism 同名不同功能
int add(int a, int b) {
    return a + b;
}

// Same function with different arguments, 可不同个数variables, 可不同type;通过对function signature(name&parameter个数和type)来找，
// 如果找不到，尝试type conversion，再找不到或找到多个throw error
double add(int a, int b, double c) {
    return (double)a + (double)b + c;
}

int main() {

    A a1; // Will not throw error

    A a2(25);

    cout << a1.data << endl;
    cout << a2.data << endl;

    int a = 5, b = 7;
    double c = 11.2;
    cout << add(a,b) << endl;
    cout << add(a,b,c) << endl;

    return 0;
}

// Function overriding: 同function同parameters，不同definition
// To change change or extend the behavior of an inherited function; done at run time(overloading at complie time)
// Overridden functions are in different scope(overloaded functions are in same scope)

// Functions that cannot be overloaded
// 1. 只有return type不一样
// 2. 如果其中一个是static member function
class Test {
    static void fun(int i) {}
    void fun(int i) {}   
 };
// 3. 如果只差a pointer * versus an array []
//int fun(int *ptr);
//int fun(int ptr[]); // redeclaration of fun(int *ptr)
// 4. 一个是另一个的pointer type
// void h(int ());
// void h(int (*)()); // redeclaration of h(int())
// 5. 只差const/volatile
int f ( int x) {
    return x+10;
}

int f ( const int x) {
    return x+10;
}
// 6. 只有default arguments不一样的

// Function can be overloaded across namespace(example below)
// Original X.h:
// int f(int);
// Original Y.h:
// int f(char);

// Original program.c:
// #include "X.h"
// #include "Y.h"

// int main(){
   //f('a');   // calls f(char) from Y.h
// }
