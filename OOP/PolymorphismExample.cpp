#include <iostream>
using namespace std;

class Object {
public:
    virtual bool equals(Object* obj) { cout << "Object::equals(Object*)\n"; return true; }
};

class Fruit : public Object {
public:
    bool equals(Fruit* fruit) { cout << "Fruit::equals(Fruit*)\n"; return true; }  // overload (new signature)
    bool equals(Object* obj) override { cout << "Fruit::equals(Object*)\n"; return true; }  // override
};

int main() {
    Object* o = new Object();
    Fruit* f = new Fruit();
    Object* of = new Fruit();

    f->equals(o);    
    f->equals(f);    
    f->equals(of);
    o->equals(o);
    o->equals(f);
    o->equals(of);
    of->equals(o); // At compile time, the declared type of of is Object*, and the compiler only sees Object::equals(Object*)
    of->equals(f); // The equals(Fruit*) overload in Fruit is invisible at that moment, so the call is bound to equals(Object*)
    of->equals(of); // Then at runtime, virtual dispatch finds Fruit::equals(Object*)

    delete o;
    delete f;
    delete of;
}
