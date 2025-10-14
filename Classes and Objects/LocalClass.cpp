// A class is a template to create objects having similar properties and behavior, a blueprint for objects
// Or it's a user-defined data type, holding its own data members and member functions

// Local class: a class declared inside a function
#include <iostream>
using namespace std;

int y = 1;

// Creating the class inside a function
void fun()
{
    static int x; // if declared as int x, it will cause error for method3 below
    enum { i = 1, j = 2 };

    // local to fun
    class Test {
        public:
            Test() { cout << "Test::Test() called" << endl; }

            // 1. the methods of a local class must be defined inside it only
            void method()
            {
                cout << "Local class Test method() called." << endl;
            }

            // 2. can have static functions, but not static data members
            static void method2()
            {
                cout << "Local class Test method2() called." << endl;
            }

            // below will cause errors
            // static int i; 

            // 4. member methods of the local class can only access static and enum variables of the enclosing function
            void method3()
            {
                cout << "Local class Test method3() called." << endl;
                cout << "x = " << x << endl; // fine as x is static
                cout << "i = " << i << endl; // fine as i is enum
            }
        
    };

    // 3. can only be used locally i.e. inside the function
    Test t; // Fine
    Test* tp; // Fine

    // the method defined inside the class works
    t.method();
    t.method3();
    // so the below codes will cause errors
    // void Test::method() { cout << "Local Class method() called."; }

    // the static method works
    Test::method2();

    // 5. local class can access global types, variables and functions
    class Test2 {
        public:
            Test t2; // Fine as a local class can use other local classes in the same function

            void method()
            {
                cout << "Local class Test2 method() called." << endl;
                cout << "y = " << y << endl; // Fine as local class member methods can access global variables
            }
    };

    Test2 tt;
    tt.method();
    tt.t2.method3();

}

int main() { 
    // below codes will cause errors
    // Test t;
    // Test* tp;

    fun(); // showing we use the local classes Test and Test2 inside the function and it will work

    return 0; 
}

// Applications:
// 1. Encapsulation / Hide information
// 2. Helper objects for function logic