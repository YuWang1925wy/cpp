// Friend functions can access all private and protected members of the class who declared the friend function
// a friend function can be 1. a global function 2. a member function of another class

#include <iostream>
using namespace std;

// 2. function of another class is the friend function of Base
// Base declaration -> member function declaration(Base&) -> friend declaration in Base
// the order in which we define the friend function of another class is important. always have to define both the classes first
class Base;

class Demo {
    public:
        void friendFunction2(Base&);
};

class Base {
    private:
        int private_var;
    protected:
        int protected_var;
    public:
        Base() {
            private_var = 1;
            protected_var = 2;
        }
        friend void friendFunction(Base& obj); // can be declared in private, protected or public. works the same
        friend void Demo::friendFunction2(Base&);

};

// 1. global function is the friend function of Base
void friendFunction(Base& obj) {
    obj.private_var = 3;
    obj.protected_var = 4;
    cout << obj.private_var << endl;
    cout << obj.protected_var << endl;
}

void Demo::friendFunction2(Base& obj) {
    cout << obj.private_var << " " << obj.protected_var << endl;
}

int main() {
    Base b;
    friendFunction(b);

    Demo d;
    d.friendFunction2(b);

    return 0;
}

/* Advantages:
1. friend functions act as a bridge between two classes by accessing their private members
2. can be used to increase the versatility of overloaded operators

Disadvantages:
1. violates the law of data hiding, reduces the effectiveness of encapsulation
2. friend functions do not participate in run-time polymorphism, i.e. can not be virtual/overridden
3. friendship is not inherited. if a base class has a friend function, then the function doesn't become a friend of the derived classes
*/