// Conversion Operator: We can also write conversion operators that can be used to convert one type to another type
#include <iostream>
using namespace std;
class Fraction
{
  private:
    int num, den;

  public:
    Fraction(int n, int d)
    {
        num = n;
        den = d;
    }

    // Conversion operator syntax: operator <target-type>() [cv-qualifiers], target-type is return type
    // const promises not to modify the object(i.e. num, den)
    operator float() const
    {
        return float(num) / float(den);
    }
};

int main()
{
    Fraction f(2, 5);
    float val = f; // val is of type float
                   // since f is Fraction, compiler looks for a way to convert it to float, so conversion operator is invoked 
                   // float val = f.operator float();
    cout << val << '\n';
    return 0;
}

// Overloaded conversion operators must be a member method. Other operators can either be the member method or the global method.