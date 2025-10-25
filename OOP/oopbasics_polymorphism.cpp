// Polymorphism
// 1. Compile time: function overloading, operator overloading
// 2. Run time: function overriding(implemented using virtual functions)

#include <iostream>
using namespace std;

// Parent Class
class Parent {
public:

    // Overloaded method 
    void func() {
        cout << "Parent.func()" << endl;
    }

    // Overloaded method 
    virtual void func(int a) {   
        cout << "Parent.func(int): " << a << endl;
    }
};

// Child Class
class Child : public Parent {
public:

    void func() {
    cout << "Child.func()" << endl;
    }

    // Overrides Parent.func(int) 
    void func(int a) override {
        cout << "Child.func(int): " << a << endl;
    }
};

int main() {
    Parent parent;
    Child child;
    Parent* polymorphicObj = new Child();  

    // Method Overloading (compile-time)
    parent.func();        
    parent.func(10);     

    // Method Overriding (runtime)
    child.func(20);      

    // Polymorphism in action
    polymorphicObj->func(30);  // compiler picks the best overload in the static type Parent and choose func(int)
                               // selected function is virtual, and the dynamic object is a Child, so the call is dispatched to the override Child::func(int)
    polymorphicObj->func();

    delete polymorphicObj;  
    return 0;
}

/*
Object oriented programming (OOP) offers several key advantages over procedural programming:
By using objects and classes, you can create reusable components(DRY: Don't Repeat Yourself principle), leading to less duplication and more efficient development.
It provides a clear and logical structure, making the code easier to understand, maintain, and debug.

Disadvantages:
- OOP is heavy for small program
- code is divided into different classes and layers, so it sometimes takes more time finding and fixing bugs
- OOP creates a lot of objects, can use more memory compared to simple programs written in a procedural way(step-by-step functions)
*/