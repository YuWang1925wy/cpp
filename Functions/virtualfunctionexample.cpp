#include <iostream>
using namespace std;

class Employee
{
  public:
    virtual void raiseSalary()
    {
        cout << "Employee salary raised (general)" << endl;
    }

    virtual void promote()
    {
        cout << "Employee promoted (general)" << endl;
    }

    // virtual destructor
    virtual ~Employee()
    {
    }
};

// Derived class: Manager
class Manager : public Employee
{
  public:
    void raiseSalary() override
    {
        cout << "Manager salary raised with incentives" << endl;
    }

    void promote() override
    {
        cout << "Manager promoted to Senior Manager" << endl;
    }
};

// Derived class: Engineer
class Engineer : public Employee
{
  public:
    void raiseSalary() override
    {
        cout << "Engineer salary raised with bonus" << endl;
    }

    void promote() override
    {
        cout << "Engineer promoted to Senior Engineer" << endl;
    }
};

int main()
{

    // Create different employees
    Manager m;
    Engineer e;

    // Array of base class pointers
    Employee *employees[2] = {&m, &e};

    // Raise salary for all employees
    cout << "--- Raising Salaries ---" << endl;
    for (int i = 0; i < 2; i++)
    {
        employees[i]->raiseSalary();
    }

    // Promote all employees
    cout << "\n--- Promotions ---" << endl;
    for (int i = 0; i < 2; i++)
    {
        employees[i]->promote();
    }

    return 0;
}