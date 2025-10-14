// Need of weak_ptr: prevent circular reference
// Circular reference: object A has a shared_ptr to object B, and B has a shared_ptr to A. Neither A nor B will be deleted, leading to a memory leak
// Non-owning reference: no affect on reference count; won't cause deletion of the object
#include <iostream>
#include <memory>
using namespace std;

class Object {
public:
    Object(int value)
        : data(value)
    {
        cout << "Object created with value: " << data
             << endl;
    }

    ~Object()
    {
        cout << "Object destroyed with value: " << data
             << endl;
    }

    int data;
};

int main()
{
    shared_ptr<Object> sharedObjectA = make_shared<Object>(42);
    cout << "sharedObjectA: " << sharedObjectA->data << endl; // sharedObjectA is a class object

    weak_ptr<Object> weakObjectA = sharedObjectA;

    // expired() check if the resource weak_ptr pointing to exists or not
    // lock() if exists, returns a shared_ptr with ownership of that resourse; if not, returns default constructed shared_ptr
    if (!weakObjectA.expired()) {
        shared_ptr<Object> sharedObjectA2 = weakObjectA.lock();
        cout << "The value stored in sharedObjectA2:" << (*sharedObjectA2).data << endl;
        cout << "Reference count of A inside lock scope: " << weakObjectA.use_count() << endl;
    }

    // use_count()
    cout << "Reference count of A out of lock scope: " << weakObjectA.use_count() << endl;

    // swap() swaps the objects managed by weak_ptr(but if use weak_ptr.lock to retrieve the data, it's unchanged)
    shared_ptr<Object> sharedObjectB = make_shared<Object>(56);
    weak_ptr<Object> weakObjectB = sharedObjectB;
    cout << "sharedObjectA: " << sharedObjectA->data << " "; // 42
    cout << "weakObjectA: " << (*weakObjectA.lock()).data << endl; // 42
    cout << "sharedObjectB: " << sharedObjectB->data << " "; // 56
    cout << "weakObjectB: " << (*weakObjectB.lock()).data << endl; // 56
    sharedObjectB.swap(sharedObjectA);
    cout << "After calling swap:" << endl;
    cout << "sharedObjectA: " << sharedObjectA->data << " "; // 56
    cout << "weakObjectA: " << (*weakObjectA.lock()).data << endl; // 42
    cout << "sharedObjectB: " << sharedObjectB->data << " "; // 42
    cout << "weakObjectB: " << (*weakObjectB.lock()).data << endl; //56

    // reset() clear the weak_ptr
    sharedObjectA.reset(); // 56 is destroyed first
    weakObjectB.reset();
    cout << "Reference count of A: " << sharedObjectA.use_count() << endl;
    cout << "Object A expired? " << weakObjectB.expired() << endl;
    cout << "Reference count of B: " << sharedObjectB.use_count() << endl; // B(42) is not freed yet, since only the weak pointer is reset
    cout << "Object B expired? " << weakObjectA.expired() << endl;
    cout << "End of the Program" << endl;

    return 0;
}