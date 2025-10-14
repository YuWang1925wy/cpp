// Identifiers: unique names assigned to variables, functions, classes, structs, or other entities within the program
// can consist of digits, letters and underscores; can begin with letters and underscores

#include <iostream>
using namespace std;

// Car identifier is used to refer to a class
class Car {
    string Brand;
    string model;
    int year;
};

// getSum identifier is used to refer to a function
void getSum(int a, int b){
    int _sum = a + b;
    cout << "The sum is: " << _sum;
}

int main(){

    // identifiers used as variable names
    int studentAge = 20;
    double accountBalance = 1000.50;
    string student_Name = "Karan";

    getSum(2, 10);

    return 0;
}

// Keywords
