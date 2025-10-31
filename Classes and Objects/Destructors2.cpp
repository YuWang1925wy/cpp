// destructor application: when a class contains a pointer to memory allocated in the class, 
//                         we should write a destructor to release memory before the class instance is destroyed

#include <iostream>
using namespace std;

class MyClass {
private:

    // Pointer to dynamically allocated memory
    int* data;

public:
    MyClass(int value) {
        data = new int;
        *data = value;
        cout << *data << endl;
    }

    // User-defined destructor: Free the dynamically allocated memory
    ~MyClass() {
        
        // Deallocate the dynamically allocated memory
        delete data;  
        cout << "Destructor: Memory deallocated";
    }
};

int main() {
    MyClass obj1(10);
    return 0;
}
