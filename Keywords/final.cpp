// the final keyword is used to prevent further overriding or inheritance of
// 1. virtual functions
// 2. classes

#include <iostream>
using namespace std;

class Base {
    public:
        virtual void show() final {  // Cannot be overridden
            cout << "Base show\n";
        }
    };
    
class Derived : public Base {
    public:
        //void show() override {       -> Error: cannot override final function
        //    cout << "Derived show\n";
        //}
};

class FinalClass final { // Cannot be inherited
    public:
        void display() {
            cout << "This is a final class\n";
        }
    };
    
// class SubClass : public FinalClass {  -> Error: cannot inherit from final class 
// };

// Why use final?
// prevent accidental overriding/inheritance; design clarity
// optimization: helps complier make better decisions for inlining and performance