// is an instance member function, invoked automatically whenever an object is going to be destroyed
/* Syntax
~className(){
    // Body of destructor
}

Calling destructors explicity:
object_name.~class_name()
*/
#include <iostream>
using namespace std;

class Test {
private:
    int count;
public:
    Test(int value){
        count = value;
        cout << "No. of Object created: " << count << endl;
    }
    ~Test() {
        
        // It will print count in decending order
        cout << "No. of Object destroyed: " << count << endl;
    }
};

int main() {
    Test t1(1), t2(2), t3(3); // t3 is destroyed first
    return 0;
}

// A destructor function is called when the object goes out of scope(function ends, program ends, a block containing local variables ends, or delete is called)
/* Characteristics of destructors:
1. it's the only one way to destroy the object created by the constructor, so it can't be overloaded(can't define more than one destructor)
2. can't be declared static or const
3. don't require arguments, nor returns any value
*/
