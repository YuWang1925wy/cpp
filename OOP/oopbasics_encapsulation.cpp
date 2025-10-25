// Encapsulation: the process of wrapping data and the methods into a single unit, typically a class. 
// prevents the data from being accessed by the code outside the shield
// variables/data hidden from any other class technically can be accessed only through any member function of the class

#include <iostream>
#include <string>
using namespace std;

class Employee {
    
    // Private fields 
private:
    int id;
    string name;

public:

    // Setter methods
    void setId(int id) {
        this->id = id;
    }

    void setName(string name) {
        this->name = name;
    }

    // Getter methods
    int getId() {
        return id;
    }

    string getName() {
        return name;
    }
};

int main() {
    Employee emp;

    // Using setters
    emp.setId(101);
    emp.setName("Geek");

    // Using getters
    cout << "Employee ID: " << emp.getId() << endl;
    cout << "Employee Name: " << emp.getName() << endl;

    return 0;
}