// Overloading ++ operator
#include <iostream>
using namespace std;

class overload {
private:
    int count;

public:
    overload(int i) : count(i) {}

    // pre/post指的是increment在return前还是后
    // return old value, then increment(postfix, i++)
    overload operator++(int) { // dummy int isn't used, it just tells the compiler "this is the postfix form"
        overload temp = *this;
        ++count;
        return temp; // the value we return is the old value
    } 
    // increment, then return new value(prefix, ++i)
    overload& operator++() {
        ++count;
        return *this;
    }
    void Display() { cout << count << endl; }
};

int main()
{
    overload i(5);
    overload post(5);
    overload pre(5);

    pre = ++i; // i.operator++(); for compiler
    cout << "i.count = ";
    i.Display();
    cout << "pre.count = ";
    pre.Display();

    i++; // just to show diff
    i++; // just to show diff
    post = i++; // i.operator(0); for compiler
    cout << "post.count = ";
    post.Display();
    cout << "i.count = ";
    i.Display();
    return 0;
}