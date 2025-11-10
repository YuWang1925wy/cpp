// move constructor: allows us to transfer the contents of one object to another without copying the data
// faster than copying
// syntax: class_name(class_name&& other);
// class_name&& is an rvalue reference to another object of the same class
// && allows the function to bind to temporary(rvalue) objects
// an rvalue reference is a reference that can bind to a temporary(rvalue) instead of a named variable(lvalue)
// lvalue: an object that has a persistent location in memory e.g. int a = 5; a is an lvalue
// rvalue: a temporary value, typically appearing on the right-hand side of an assignment  e.g. 5, a+2, std::string("Hi")

#include <iostream>
using namespace std;

class Geeks {
    private:
        int* ptr;
    public:
        Geeks(int v) {
            ptr = new int(v);
            cout << "Constructor called" << endl;
        }

        // move constructor
        Geeks(Geeks&& obj) {
            ptr = obj.ptr;
            obj.ptr = nullptr;
            cout << "Move constructor called" << endl;
        }

        ~Geeks() {
            if (ptr != nullptr) {
                cout << "Desctructor deleting data: " << *ptr << endl;
            } else {
                cout << "Destructor called on nullptr\n";
            }
            delete ptr;
        }

        void display() {
            if (ptr) {
                cout << "value: " << *ptr << endl;
            } else {
                cout << "No data\n";
            }
        }
};

int main() {
    Geeks g1(1);
    Geeks g2 = std::move(g1); // equals to Geeks obj2 = static_cast<Geeks&&>(obj1);
                              // std::move() performs a type cast to an rvalue reference, telling the compiler to treat g1 as a temporary
                              // and then the move constructor is called

    cout << "After move: \n";
    cout << "g1: \n";
    g1.display();
    cout << "g2: \n";
    g2.display();

    return 0;
}