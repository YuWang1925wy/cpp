// Noexcept move constructor: guarantees it won't throw any exceptions

#include <iostream>
#include <vector>
using namespace std;

// class without noexcept move constructor
class A {
    public:
        A() {
            cout << "Constructor called\n";
        }

        // move constructor
        A(A&& other) {
            cout << "Move constructor called\n";
        }

        // copy constructor
        A(const A& other) {
            cout << "Copy constructor called\n";
        }
};

// class with noexcept move constructor
class Test {
    public:
        Test() {
            cout << "Test constructor called\n";
        }

        Test(Test&& other) noexcept {
            cout << "Test move constructor called\n";
        }

        Test(const Test& other) {
            cout << "Test copy constructor called\n";
        }
};

int main() {
    vector<A> v;

    v.reserve(2); // reserve space for at least 2 elements to avoid immediate resizing

    v.push_back(A()); // temporary A is constructed and then moved into the vector
    v.push_back(A());

    cout << "Resize happens\n";

    v.push_back(A()); // deal with the third element first, and then copy the first two elements to new location
    getchar();        // STL implementation says: only use `move` during reallocation if it's guaranteed not to throw. otherwise we play it safe and use `copy`  

    vector<Test> vt;
    vt.reserve(2);
    Test t;
    vt.push_back(Test());
    vt.push_back(Test());

    cout << "Resize happens\n";
    vt.push_back(Test()); // with noexcept keyword in the move constructor, compiler is guaranteed to use `move` for reallocation

    return 0;
}

/* Why use noexcept?
It helps the compiler optimize our code, especially with STL containers like std::vector.
If a move constructor is not marked noexcept, some STL operations will fall back to slower copy operations to avoid potential exceptions.
*/