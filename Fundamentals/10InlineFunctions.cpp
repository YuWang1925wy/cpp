// Inline functions: reduce the overhead related to a function call(extra work the program pays every time the function is called)
// how: suggests the complier that it should replace the functions call with the actual code of the function to avoid the overheads
// overhead: when function is called -> CPU stores the return address/copies argument to the call stack/transfer control to the function
// -> after execution, return value is stored/control is returned to the caller

#include <iostream>
using namespace std;

// Inline function
inline int square(int x) { // inline return_type function_name(params)
	return x * x;
}

// inline functions in class
class A {
    public:
    
        // declare inline
        inline int square(int x);
};
// functions defined inside the class are implicitly inline
// if declare inside the class and define outside the class, need to explicitly define the class with the keyword inline
    
// Define the function(explicitly)
inline int A::square(int x) {
        return x*x;
}
// compiler cannot inline the virtual function
// reasons: 1. virtual functions are resolved at runtime instead of compile time

int main() {
	int num = 5;
	
	// Calling inline function
	int res = square(num);
	cout << res << endl;

    A obj;
    cout << obj.square(3) << endl;

    // goto statement syntax
    // this statement will be executed
    cout << "First Statement" << endl;

    goto skip_in_between;
    cout << "Second Statement" << endl; // will be skipped
    
    skip_in_between:
    cout << "Third Statement" << endl;

	return 0;
}

// The complier may not performing inlining when:
// the function contains a loop/static variables/is recursive/a switch or goto statement
// or the return type is other than void, and the return statement doesn't exist in a function body (该return不return

// inline function 应该 as small as possible(time spent during a function call > function body execution time)