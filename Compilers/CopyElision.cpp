#include <iostream>
using namespace std;

class B {
    public:
        B(const char* str = "\0"){
            cout << "Parameterized constructor called" << endl;
        }
        B(const B& b){
            cout << "Copy construcotr called" << endl;
        }
};

int main(){
    /*
    According to theory, when the object "ob" is being constructed, 
    one argument constructor is used to convert "copy me" to a temporary object & 
    that temporary object is copied to the object "ob". So the statement

    B ob = "copy me"; // Also RVO form to represent
    should be broken down by the compiler as:

    B ob = B("copy me"); // Also NRVO form to represent
    However, most C++ compilers avoid such overheads of creating a temporary object & then copying it.

    The modern compilers break down the statement
    B ob = "copy me"; //copy initialization
    as
    B ob("copy me"); //direct initialization
    and thus eliding call to copy constructor.
    */
    B ob = "copy me";
    return 0;
}

/*
If we compile with:
g++ CopyElision.cpp -fno-elide-constructors
the compiler doesn't elide the call to copy construct(disable the copy elision)
*/