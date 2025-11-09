// friend functions/classes: allow certain functions/classes to access the private and protected members of another class
#include <iostream>
using namespace std;

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

        friend class Friend; // syntax: friend class class_name;
                             // Base has a friend class Friend -> Friend type can access Base private and protected members
                             // can put this line anywhere in the Base class body, i.e. private, protected or public, it works the same
};

class Friend {
    public:
        void display(Base& b) {
            b.private_var = 3;
            b.protected_var = 4;
            cout << b.private_var << endl;
            cout << b.protected_var << endl;
        }
};

int main() {
    Base b;
    Friend f;
    f.display(b);

    return 0;
}