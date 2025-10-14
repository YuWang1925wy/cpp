#include <iostream>
using namespace std;

int func() {
  // Static variable
  static int count = 0;
  count++;
  return count;
}

class A {
    public:
        int x;
    
        // Defining mutable variable y
        // now this can be modified
        mutable int y;
    
        A(): x(4), y(10) {}
    };

int main() {

    // auto storage class is the default class of all the variables declared inside a block
    // Earlier in C++, we could use the auto keyword to declare the auto variables explicitly but after C++11, 
    // the meaning of auto keyword is changed, and we could no longer use it to define the auto variables.

    // extern storage class simply tells us that the variable is defined elsewhere and not within the same scope (or even source file) where it is used
    // Example: Suppose x is initialized in other file
    // Telling compiler that variable x is extern variable
    // and has been defined elsewhere
    //extern int x;
    //int main() {
  	    // Printing the value of x
        // cout << x;
        // return 0;
    //}

    // static storage class is used to declare static variables that have the property of preserving their value even after they are out of their scope
    cout << func() << "\n";  // output 1
    cout << func(); // output 2

    // mutable storage class
    // a is created as constant
    const A a;

    // Trying to change the value
    a.y = 200;
    cout << a.y;

    // Uncommenting below lines
    // will throw error
    /* a.x = 8;
    cout << a.x; */
    
    return 0;
}