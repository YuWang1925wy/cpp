// all members of a union are stored in the same memory location
// since all members share the same memory, changing the value of one member overwrites the value of others
#include <iostream>
using namespace std;

// 1. Example of size of the union 
union A {
    int x; // 4 bytes
    char y; // 1 byte
} a; // can declare a variable at the declaration of union

union B {
    int arr[10]; // 4 * 10 = 40 bytes
    char y; // 1 byte
};

// 2. Example of nested union
struct Employee {
    char name[50];
    int id;

    union Pay {
        float hourlyRate;
        float salary;
    } payment; // have to declare a union member in the struct so each Employee actually contains this union
};

// 3. Example of anonymous unions
struct Employee2 {
    int id;

    union { // the member variable names have to be unique
        float hourlyRate;
        float salary;
    };
};

int main() {
    // 1. size of union = size of the largest member of the union
    cout << "Size of A: " << sizeof(A) << endl;
    cout << "Size of B: " << sizeof(B) << endl;

    A a1;
    a1.x = 1;
    a1.y = 'A'; // a1.x is overwrited
    cout << a1.x << endl; // typy char(a1.y) will convert to type int(a1.x) first before print
    
    // 2. nested union: defined within a structure, class or another union
    Employee e1;
    e1.id = 101;
    e1.payment.hourlyRate = 300.0; // accessing nested union member using dot operator
    cout << "Employee id: " << e1.id << endl;
    cout << "Hourly rate: " << e1.payment.hourlyRate << endl;

    e1.payment.salary = 125000.0;
    cout << "Now the hourly rate shows: " << e1.payment.hourlyRate << endl;

    // 3. anonymous unition: declared without a name inside a main function
    //can directly access the data member of the union
    // mostly used in nested unions where they can be accessed as if they are the members of the outer union/structure
    Employee2 e;
    e.id = 102;
    e.hourlyRate = 300.0;
    cout << "Employee id: " << e.id << endl;
    cout << "Hourly rate: " << e.hourlyRate << endl;

    return 0;
}

/* why do we need unions?
1. for memory efficiency
2. used to map to hardware registers that might have different interpertations depending on the context
e.g. a register that can be read as a status flag or written as a command
3. suitable for representing data that can take on one of several different types but never simultaneously
*/