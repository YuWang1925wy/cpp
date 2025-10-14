#include <iostream>
using namespace std;

// Recursive function should have 1.recursive case(the way recursive call is present) 2.base condition(什么时候停)
void printHello(int n) {
    
    // Base Case
    if (n == 0) return;
    
    cout << "Hello" << endl;
    
    printHello(n - 1); // self-calling
}

// tree recursion: a function calls itself more than once
void f(int n) {
    cout << "F(" << n << ")'s Stack Frame Pushed\n";
    if (n > 1) { // n=1时不进，直接到下面一个cout
        f(n-1); // direct recursion: calls itself from within its body
        f(n-1);
    }
    cout << "F(" << n << ")'s Stack Frame Removed\n";
}
// head recursion: recursive call happens before any processing in the function, process while returning
void head(int n) {
    if (n != 0) {
        // Recursive call before processing
        head(n - 1);
    }
    cout << n << " ";
}

// tail recursion: process first, recursive call is the last operation
void tail(int n) {
    if (n == 0)
        return;
    cout << n << " ";

    // Recursive call after processing
    tail(n - 1);
}

// nested recursion: the argument to a function is itself a recursive call
int nested(int n) {
    if (n > 100)
        return n - 10;

    // Recursive call inside another recursive call
    return nested(nested(n + 11));
}

// indirect recursion: a function calls another function that eventually calls itself
void funcA(int);
void funcB(int);
void funcA(int n) {
    if (n > 0) {
        cout << n << " ";
        funcB(n - 1);
    }
}

void funcB(int n) {
    if (n > 0) {
        cout << n << " ";
        funcA(n / 2);
    }
}

int main() {
    printHello(2);
    f(3);

    cout << "Results of Head Recursion" << endl;
    head(2);
    cout << endl;
    cout << "Results of Tail Recursion" << endl;
    tail(5);
    cout << endl;
    cout << "Results of Nested Recursion" << endl;
    cout << nested(95) << endl;
    cout << "Results of Indirect Recursion" << endl;
    funcA(10);
    return 0;
}

// Memory Management in Recursion: functions没return之前stack frame被放到top of existing stack frames；return之后值传给function before current topmost function
// The complier uses and instruction pointer to keep track of the location to return to

// Stack Overflow: recursive calls太多，stack memory gets exhausted所以不能store more data leading to program's termination

// Drawbacks of Recursion
// performance: less efficient than iterative algorithms in some cases, particularly if the data structure is large/recursion goes too deep
// Memory usage can use a lot of memory
// can be more complex than iterative algorithms
// can be more difficult to debug
// stack overflow error can crash the program

// Call Stack
// Functions parameters, local variables declared within the function, return address form a stack frame(activation record)
// which is pushed onto the call stack when the function is called
// a stack pointer keeps track of the top of the stack