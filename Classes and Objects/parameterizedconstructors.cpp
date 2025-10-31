#include <iostream>
#include <string.h>
using namespace std;

class Student {
    int rno;
    string name;
    double fee;

public:
  
  	// Declaration of parameterized constructor
    Student(int, string, double);
    void display();
};

// 1. Parameterized constructor outside class
Student::Student(int no, string n, double f) {
    rno = no;
    name = n;
    fee = f;
}

void Student::display() {
    cout << rno << "\t" << name << "\t" << fee << endl;
}

class A {
    public:
        int data;
    
        // 2. Parameterized constructor with default values
        A(int x = 5) : data(x) {}  // 3. syntax for member initializer list: class_name(T a, T b) : member1(a), member2(b) {}
};

int main() {
  
  	// Creating object with members initialized to given values
    Student s(1001, "Ram", 10000); // implicit call the constructor
    Student s2 = Student(1002, "Yu", 0); // explicit call the constructor
    s.display();
    s2.display();

    A a1; // Will not throw error, as the constructor has default arguments
    A a2(25);

    cout << "a1: " << a1.data << endl;
    cout << "a2: " << a2.data << endl;
    return 0;
}