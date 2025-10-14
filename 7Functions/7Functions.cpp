#include <iostream>
#include <vector>
using namespace std;

// Function Declaration introduces the function to the compiler
// Declaration
int add(int, int);

// Void function definition
void hello() {
    cout << "GeeksforGeeks" << endl;
}

// Return-type function definition
int square(int x) {
    return x * x;
}

// Arguments are pass by value: a variable's value is copied and then passed to the function
// any changes to the parameter inside the function will not affect the variable's original value in the caller
void change1(int a) {

    // Modifying arguments
    a = 22;
}

// Arguments are pass by reference: allows the function to change the value of the original argument
// useful when you have to pass large size data
void change2(int& a) {
  
    // Modifying arguments
    a = 22;
}

// Arguments are pass by pointer: pass the raw address of the argument as the parameter to the function instead of reference
// allows changes to the value of the original argument
void change3(int* a) {
  
    // Modifying arguments
    *a = 22;
}

void print(const vector<int>& v) {
    for (auto x : v) cout << x << " ";
    cout << "\n";
}

int main() {

    // Calling the void function
    hello();

    // Calling the return-type function
    int result = square(5);
    cout << "Square of 5 is: " << result << endl;

    int x = 5;
    change1(x);
    cout << "Pass by value: " << x << endl;
    change2(x);
    cout << "Pass by reference: " << x << endl;

    x = 5;
    cout << "Change the value of x back to original one after pass by reference function: " << x << endl;
    change3(&x);
    cout << "Pass by pointer: " << x << endl;

    // Lambda expression: allow inline functions which can be used for short snippets of code that are not going to be reused
    // they don't require a name
    // mostly used in STL algorithms as callback functions
    vector<int> v1, v2;

    // [&]: capture all external variables by reference
    // [=]: capture all external variables by value
    // [a, &b]: capture 'a' by value and 'b' by reference
    // side notes: A lambda with an empty capture clause [] can only access variables which are local to it

    // Capture all by reference
    auto byRef = [&](int m) {    
        v1.push_back(m);
        v2.push_back(m);
    };

    // Capture all by value (copies); need 'mutable' to modify the copies
    auto byVal = [=](int m) mutable { // we need mutable here because, by default, value captured objects are const
        v1.push_back(m);   // modifies the lambda's private copies, NOT the originals
        v2.push_back(m);
    };

    // Capture v1 by reference, v2 by value
    auto mixed = [&v1, v2](int m) mutable {
        v1.push_back(m);   // original v1
        v2.push_back(m);   // copy of v2 inside the lambda
    };

    byRef(20);   // pushes 20 into original v1 and v2
    byVal(234);  // modifies only the copies; originals unchanged
    mixed(10);   // pushes 10 into original v1; v2 (copy) only inside lambda

    cout << "v1: " << endl;
    print(v1);   // -> 20 10
    cout << "v2: " << endl;
    print(v2);   // -> 20

    // Application of Lambda expression
    vector<int> v = {5, 1, 8, 3, 9, 2};

	// Sort in descending order
	sort(v.begin(), v.end(), [] (const int& a, const int&b) {
		return a > b;
	});

	for (int x : v)
		cout << x << " ";
    // same as
    // auto desc = [](int a, int b){ return a > b; };
    // std::sort(v.begin(), v.end(), desc);

    return 0;
}

// if a function is defined after the main function or any other function that tries to use it, 
// the compiler will not recognize it unless a declaration is provided earlier in the code
int add(int a, int b) {
    return a + b;
}