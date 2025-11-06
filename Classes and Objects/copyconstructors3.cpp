/* When is copy constructor called: 
1. when an object of the class is return by value
2. when an object of the class is passed(to a function) by values as an argument
3. when an object is constructed based on another object of the same class
4. when an object is constructed using initialization lists with braces
5. when the compiler generates a temporary object
*/

// example
#include <iostream>
using namespace std;

class storeVal {
    public:
        storeVal() {}
        storeVal(const storeVal& s){
            cout << "Copy constructor is called." << endl;
        }
};

storeVal foo(){
    storeVal a, b;
    if (std::rand() % 2) return a;
    else return b; // often prevents NRVO -> copy/move ctor runs
                   // if we initialize one object and return it, most compliers construct obj3(in main) directly in its final storage using NRVO, 
                   // so no temporary is created and copy constructor won't be called 
}

void foo2(storeVal obj){
    return;
}

int main(){
    storeVal obj1;

    cout << "case 1: when an object is returned by value" << endl;
    storeVal obj3 = foo();

    cout << "case 2: when an object is passed by value" << endl;
    foo2(obj1);

    cout << "case 3: when an object is constructed based on another object of the same class" << endl;
    storeVal obj2 = obj1;

    return 0;

}