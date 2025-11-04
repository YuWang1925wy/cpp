// allows objects to behave like basic data types
// reduces the need for extra function calls(e.g. we can overload + instead of define add())
#include <iostream>
using namespace std;

struct Number
{
    int value;

    Number(int v)
    {
        value = v;
        cout << "Number constructor called. " << endl;
    }

    // Overload + operator
    Number operator+(const Number &n)
    {
        return Number(value + n.value);
    }

    void display()
    {
        cout << "Display: " << value << endl;
    }
};

int main()
{
    Number n1(5), n2(10);
    Number n3 = n1 + n2; // constructor and overloaded operator + are called
    n3.display();
}

/*
Operators that cannot be overloaded

1) Scope Resolution Operator  (::)    

2) Ternary or Conditional Operator (?:)   

3) Member Access or Dot operator  (.)    

4) Pointer-to-member Operator (.*)  

5) Object size Operator (sizeof) 

6) Object type Operator(typeid) 

7) static_cast (casting operator)

8) const_cast (casting operator)

9) reinterpret_cast (casting operator)

10) dynamic_cast (casting operator)
*/