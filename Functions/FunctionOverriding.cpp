// Function overriding is a type of polymorphism(a form of runtime polymorphism)

#include <iostream>
using namespace std;

class Animal {
    public:
        virtual void sound() { // condition 1: base class function must be virtual
            cout << "Animal makes a sound\n";
        }
    };
    
class Dog : public Animal {
    public:
        // override the virtual function sound() with the override keyword; will complie without the keyword, but lead to unexpected behavior
        void sound() override {   // condition 2: derived class must use same signature(return type, function name, parameters)
            cout << "Dog barks\n";
        }
};

int main() {
    Animal a;
    Dog d;
    a.sound(); // call the function with a base class object -> base class version is executed
    d.sound(); // call the function with a derived class object -> derived class version is executed
    
    return 0;
}

// Advantages of Function Overriding
// 1. Dynamic behavior at runtime
// 2. Promotes code reuse through inheritance
// 3. Changes in base class can affect derived class easily
// 4. Enables design patterns like Strategy, Command etc
// 5. Encourage loose coupling by coding to base class interfaces

// Limitations of Function Overriding
// 1. Slightly slower than normal function calls due to virtual table lookup
// 2. Adds memory overhead(vtable, vptr)
// 3. Complexity increases in large inheritance hierarchies
// 4. Mistakes in overriding may cause bugs if signatures don't match
// 5. Requires caredful design to avoid maintenance issues