#include <iostream>
using namespace std;

void f() {
  
    // Static variable in a function: gets allocated for the lifetime of the program
    // won't get initialized every time the function is called
    static int count = 0;

    // The value will be updated and carried over to the next function call(下次call不重新initialize)
    count++;
  	cout << count << " ";
}

// Coroutine example
int range(int a, int b)
{
    static long long int i;
    static int state = 0;
    switch (state) {
    case 0: 
        cout << "initialize range" << endl;
        i = a; // initialize on first entry
        state = 1; // next: yield current i
        [[fallthrough]];
    case 1: // yield i
        if (i < b) {
            state = 2;  // after returning, next state prints "control at range"
            return i; // transfer control back to main
        } else {
            state = 0;  // reset when done
            return 0;
        }
    case 2:  // executed on the next call
        cout << "control at range" << endl;
        ++i;  // advance
        state = 1;  // then yield again
        return i < b ? i : (state = 0, 0);
    }
    return 0; // safety
}

// Static Data Member in a class: shared by the objects
class GfG {
    public:
      
        // Static data member
        static int i;
    
        GfG(){
            // Do nothing
        };

        // Static member function
        // only allowed to access the static data member/other static member functions
        static void printMsg() { cout << "Welcome to GfG!" << endl; }
    };
    
// Static member inintialization: should be initialized explicitly using the class name and scope resolution operator outside the class
int GfG::i = 1;

// Global static variable
// declared outside of any class or function
// can be access only within the current file where it's defined(scope limited to current translation unit/internal linkage)
static int c = 0;

void increment() {
    c++;
    cout << c << " ";
}

int main() {
  
  	// Calling function f() 3 times
    cout << "Static variable in a function:" << endl;
    for (int j = 0; j < 3; j++)
        f();
    cout << endl;

    // print the static data member in a class
    cout << "Static data member:" << endl;
    cout << GfG::i << endl;

    // Invoking a static member function
    cout << "Calling static function in GfG class: " << endl;
    GfG::printMsg();

    // Interact with global static variable
    cout << "Global static variable" << endl;
    increment();
    increment();
    cout << endl;

    // Coroutine example
    cout << "Coroutine Example:" << endl;
    int i; 
    while ((i = range(1, 5)))
        cout << "control at main: " << i << endl;
  
    return 0;
}

// Static variable(in a function) applications
// 1. Return local variable address from the function.
// 2. Useful for implementing coroutines in C++ or any other application where the previous state of function needs to be stored.
// 3. Memoization in recursive calls

// Static data members(in a class) applications:
// 1. Counting Objects of a Class
// 2. Store and share configuration or settings globally.
// 3. Tracking Shared Resources
// 4. Regulate or limit operations performed by multiple objects.
// 5. Ensure a class has only one instance by using static members.

// Static member functions applications:
// 1. Accessing Static Member Variables
// 2. Implement helper functions that do not depend on specific instances.
// 3. Singleton Pattern Implementation
// 4. Factory Methods to create and return objects without requiring an instance of the class.
// 5. Logging and Debugging

// Global static variable applications:
// 1. Limiting variable scope to a file to prevent conflicts by ensuring the variable is accessible only within the file.
// 2. Global counters or flags.
// 3. Store settings or values that are specific to the functionality implemented in a single file.
// 4. Use for shared resources in scenarios where frequent initialization and destruction can be avoided.
// 5. Shared state across functions in a file.

// Coroutines are general control structures where flow control is cooperatively passed between two different routines without returning
// have many entry points for suspending and resuming excution; link together to form a pipeline c1->c2->c3&c4->c5
// threads: operating system/runtime environment that switches between threads according to the scheduler
// coroutines: programmer/programming language which decides when to switch