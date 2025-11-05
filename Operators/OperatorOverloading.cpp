// allows objects to behave like basic data types
// reduces the need for extra function calls(e.g. we can overload + instead of define add())
// for operator loading to work, at least one of the operands must be a user-defined class object
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
Operators that cannot be overloaded(and reasons)

1) Scope Resolution Operator  (::)    
确定要用哪个identifier by specifying a namespace
completely evaluated at runtime, works on names rather than values
是note expressions with data types and cpp has no syntax for capturing them if it were overloaded

2) Ternary or Conditional Operator (?:)   
A function overloading the ternary operator for a class say ABC using the definition
ABC operator ?: (bool condition, ABC trueExpr, ABC falseExpr);
would not be able to guarantee that only one of the expressions was evaluated. Thus, the ternary operator cannot be overloaded.

3) Member Access or Dot operator  (.)    
Complex c3 = c1 + c2; // internally translated to Complex c3 = c1.operator+ (c2);
argument c1 is implicitly passed using the . operator

4) Pointer-to-member Operator (.*)  

5) Object size Operator (sizeof): 
size of object/data type evaluated by the compiler and can not be done during runtime
proper incrementing of a pointer in an array of objects relies on sizeof implicitly
altering its meaning using overloading would cause a fundamental part of the language to collaspe

6) Object type Operator(typeid): recover指针或reference代表的object的type
重点是uniquely identify a type

7) static_cast (casting operator)

8) const_cast (casting operator)

9) reinterpret_cast (casting operator)

10) dynamic_cast (casting operator)
*/