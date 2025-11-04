// overloading ->
#include <iostream>
using namespace std;

class GFG {
public:
    int num;
    GFG(int j) { num = j; } // constructor
    GFG* operator->() { return this; }
};

int main()
{
    GFG T(5);
    GFG* Ptr = &T;

    // Accessing num normally
    cout << "T.num = " << T.num << endl;

    // Accessing num using normal object pointer
    cout << "Ptr->num = " << Ptr->num << endl;

    // Accessing num using -> operator
    cout << "T->num = " << T->num << endl; // (T.operator->())->num for compiler, compiler actually automatically adds a ->, so we have to put a member after -> in our code

    return 0;
}