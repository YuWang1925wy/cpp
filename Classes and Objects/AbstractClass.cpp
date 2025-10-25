/* 
pure virtual function: a virtual function with no implementation in the base class
- syntax: virtual void function_name() = 0;
- forces derived classes to override it

abstract class: a class with at least one pure virtual function
- can not be instantiated
- serves as a blueprint for derived classes which must provide their own implementation
- is used to define interfaces and ensure common structure among derived classes
*/

#include <iostream>
using namespace std;

class Shape {
public:
    virtual ~Shape() = default;
    virtual void draw() = 0; // Pure virtual function
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing Circle\n";
    }
};

int main() {
    
    // Error in the below line : Cannot create 
    // object of abstract class
    // Shape s;      
    
    // Pointer to abstract class
    Shape* s = new Circle(); 
    
    // Output: Drawing Circle
    s->draw();    
    
    delete s;
}