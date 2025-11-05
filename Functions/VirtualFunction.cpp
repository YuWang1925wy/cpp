#include <iostream>
using namespace std;

class Shape
{
  public:
  
    // Virtual function
    virtual void calculate()
    {
        cout << "Area of your Shape ";
    }

    // Virtual destructor: 1. when a derived class object is deleted through a base class pointer,
    // a virtual destructor in the base class ensures that both the derived and base class destructors are called
    // 2. if a class has any virtual functions, its destructor should also be declared virtual
    virtual ~Shape()
    {
        cout << "Shape Destructor called\n";
    }
};

class Rectangle : public Shape
{
  public:
    int width, height, area;

    void calculate() override
    {
        width = 5;
        height = 10;

        area = height * width;
        cout << "Area of Rectangle: " << area << "\n";
    }

    ~Rectangle()
    {
        cout << "Rectangle Destructor called\n";
    }
};

class Square : public Shape
{
  public:
    int side, area;

    void calculate() override
    {
        side = 7;
        area = side * side;
        cout << "Area of Square: " << area << "\n";
    }

    ~Square()
    {
        cout << "Square Destructor called\n";
    }
};

int main()
{

    Shape *S;

    Rectangle r;
    S = &r;
    S->calculate();

    Square sq;
    S = &sq;
    S->calculate();

    return 0;
}

/* Rules of Virtual Functions
1. if virtual function is not overriden in derived class, base version is used
2. must have same prototype in base and derived class(return type, function name, parameter types, CV-qualifier like const/volatile, ref-qualifier(&/&&), exception spec/noexcept)
3. used through a class pointer/reference to achieve runtime polymorphism
4. a class may have a virtual destructor in case of dynamic memory allocation, but never has a virtual constructor
5. can not be static, but can be friend functions of another class

Limitations of Virtual Functions:
1. slower
2. difficult to debug as it makes it more difficult to figure out where a function is being called from
*/