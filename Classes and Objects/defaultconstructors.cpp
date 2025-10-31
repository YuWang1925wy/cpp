// default constructor: constructors that take no arguments
/* Use cases of default constructors:
1. creating arrays or vectors of objects
2. needed when using STL containers e.g vector<Class>
3. when objects need to be initialized to default values
4. required in generic programming and templates
*/
#include <iostream>
using namespace std;

class GFG {
    string name;
    int roll;
public:
    // Default constructor
    GFG() {
        name = "Unknown";
        roll = -1;
        cout << "Default constructor called\n";
    }


    void display() {
        cout << "Name: " << name << ", Roll: " << roll << endl;
    }
};

int main() {
    GFG s1;               // Calls default constructor
    s1.display();
    
    return 0;
}

