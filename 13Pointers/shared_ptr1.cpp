// C++ program to demonstrate shared_ptr
// shared pointers point to class instance, and also point to a control block when counts the number of pointers sharing that instance
#include <iostream>
#include <memory>
using namespace std;

class A {
public:
    void show() { cout << "A::show()" << endl; }
};

int main()
{
    // 2 ways to create a shared pointer and accessing the object
    shared_ptr<A> p1(new A);
    shared_ptr<A> p3 = make_shared<A>();
    // Printing the address of the managed object
    cout << "p1: " << p1.get() << endl;
    p1->show();
    cout << "p3: " << p3.get() << endl;
  
    // Creating a new shared pointer that shares ownership
    shared_ptr<A> p2(p1);
    p2->show();
  
    // Printing addresses of p1 and p2
    cout << p1.get() << endl;
    cout << p2.get() << endl;
  
    // Returns the number of shared_ptr objects referring to the same managed object
    cout << p1.use_count() << endl;
    cout << p2.use_count() << endl;
  
    // Relinquishes ownership of p1 on the object and pointer becomes NULL
    p1.reset();
    cout << p1.get() << endl; // This will print nullptr or 0
    cout << p2.use_count() << endl;
    cout << "p2: " << p2.get() << endl;
    cout << "p2 unique? " << p2.unique() << endl;

    /*
    These lines demonstrate that p1 no longer manages an
    object (get() returns nullptr), but p2 still manages the
    same object, so its reference count is 1.
    */

    // swaps the contents(ownership) of two shared_ptr instances
    p2.swap(p3);
    cout << "p2: " << p2.get() << endl;
    cout << "p3: " << p3.get() << endl;

    return 0;
}