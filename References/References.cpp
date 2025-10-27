// A reference cannot refer to another variable once it's declared
#include <iostream>
using namespace std;

// 2. passing arguments by reference
void modifyValue(int &x) {
    x = 25;  
    cout << "modifyValue function called." << endl;
}

// 3. return reference from functions: since we return by reference, we are able to modify the original arguments(in this case) from where we call the function
int& getMax(int &a, int &b) {
    cout << "getMax function called." << endl;
    return (a > b) ? a : b;  
}

int main() {
    int x = 10;

    // it's necessary to initialize the reference at the time of creation
    int& ref = x; // 1. syntax: T &ref = var;
    cout << ref << endl;
    
    ref = 22;
    cout << "ref: " << ref << endl;
    cout << "x: " << x << endl;

    modifyValue(x);
    cout << "ref: " << ref << endl;
    cout << "x: " << x << endl;

    int y = 20;
    int &maxVal = getMax(x, y);

    // Modify the value of the larger number
    maxVal = 30;  
    cout << "x = " << x << ", y = " << y << endl;

    // 4. can modify elements if we use reference
    vector<int> vect{ 10, 20, 30, 40 };
    for (int& x : vect) {
        x = x + 5;
    }

    for (int x : vect) {
        cout << x << " ";
    }

    return 0;
}