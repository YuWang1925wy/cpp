// friend function to multiple classes

#include <iostream>
using namespace std;

class ABC; // need to declare the class first, as the friend function declaration would need the class had been declared

class XYZ {
    private:
        int _x;
    public:
        void set_data(int v) {
            _x = v;
        }
        friend void max(ABC&, XYZ&);
};

class ABC {
    private:
        int _y;
    public:
        void set_data(int v) {
            _y = v;
        }
        friend void max(ABC&, XYZ&);
};

void max(ABC& a, XYZ& b) {
    if (a._y > b._x) cout << a._y << endl; 
    else cout << b._x << endl;
}

int main() {
    ABC a;
    a.set_data(20);
    XYZ x;
    x.set_data(35);
    max(a, x);

    return 0;
}