#include <iostream>
using namespace std;

int main(){
    // a constant variable is one whose value cannot be changed after initialized
    const int num = 10;

    // Scope of variable is the region inside the program where the variable can be referred to by using its name

    // When we create or declare a variable, a fixed-size memory block is assigned to the variable, and its initial value is a garbage value. 
    // Initialization assigns a meaningful value using the assignment operator. 
    // Variables essentially manipulate specific memory locations, and their stored data is accessed via their names.

    // Bitwise operators
    int a = 6, b = 4; // 4:00000100 6:00000110

    // Binary AND operator
    cout << "a & b is " << (a & b) << endl; // 100 -> 4 (1 if both are 1)

    // Binary OR operator
    cout << "a | b is " << (a | b) << endl; // 110 -> 6 (1 if one of the bits is 1)

    // Binary XOR operator
    cout << "a ^ b is " << (a ^ b) << endl; // 010 -> 2 (1 present in either but not both)

    // Left Shift operator
    cout << "a << 1 is " << (a << 1) << endl; // 1100 -> 12

    // Right Shift operator
    cout << "a >> 1 is " << (a >> 1) << endl; // 11 -> 3

    // One’s Complement operator
    cout << "~(a) is " << ~(a); // don't understand

    // Casting operators are used to convert the value of one data type to another data type
    int x;
    (float)x;
    static_cast<float>(x);

    return 0;
}

// Quiz

// In C++ even empty classes occupy at least 1 byte to ensure the uniqueness of object addresses.
// Difference of C and C++: C++ supports both procedural and object-oriented programming that provide features like polymorphism, encapsulation, inheritance etc. while C supports only procedural programming

// Which of the following data type will throw an error on modulus operation(%)? char
// Which operator is having the right to left associativity in the following? Type cast
// Which operator is having the highest precedence in C++? 
// :: scope resolution > [] array subscript (same tier as function call (), member access ., ->) > static_cast<...>( ) and dynamic_cast<...>( ) (both are unary casts, same precedence)
// Which of the following symbol is used to declare the preprocessor directives in C++? #

// How many indicators are available in c++?

// How many types of output stream classes are there in c++?
// std::ostream (console/out device)
// std::ofstream (file output) writes to a file
// std::ostringstream (string buffer)

// carriage return /r : moves the cursor back to the start of the current line without advancing to a new line
// e.g. print("Loading 50%\rLoading 100%") This ends up showing just Loading 100%