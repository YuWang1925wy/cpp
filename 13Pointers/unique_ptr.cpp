#include <iostream>
#include <memory>
using namespace std;

struct A {
    void printA() {
        cout << "A struct...." << endl;
    }
};

int main() {
    
    A a;
    // Creating a unique pointer(feature since C++14)
    unique_ptr<A> ptr = make_unique<A>();

    // another way of creating a unique pointer
    unique_ptr<A> p1(new A);
    p1->printA();

    // displays address of the containing pointer
    cout << p1.get() << endl;

    // copy the address stroed in p1 to p2, p1 becomes NULL pointer
    unique_ptr<A> p2 = std::move(p1);
    cout << p2.get() << endl;
    cout << p1.get() << endl;

    return 0;
}

// When to use unique_ptr?
// when we want single or exclusive ownership of a resource