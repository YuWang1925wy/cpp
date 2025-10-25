/* delete operator can only delete the storage created in heap, so can't use delete for placement new
With placement new, the memory is created in stack, so the compiler knows when to delete it and it will handle deallocation automatically.
If required, and the type had a destructor, call it manually:
pInt->~int();  // trivial for int, so not needed
qInt->~int();
*/

#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

class Complex
{
private:
    double re_, im_;
public:
    // Constructor
    Complex(double re = 0, double im = 0): re_(re), im_(im)
    {
        cout << "Complex::Constructor : (" << re_
             << ", " << im_ << ")" << endl;
    }

    // Destructor
    ~Complex()
    {
        cout << "Complex::Destructor : (" << re_ << ", "
             << im_ << ")" << endl;
    }

    double normal()
    {
        return sqrt(re_*re_ + im_*im_);
    }

    void print()
    {
        cout << "sqrt(" << re_ <<"^2 + " << im_
             << "^2) = " << normal() << endl;
    }
};

// Driver code
int main()
{
    // buffer on stack
    unsigned char buf[100];

    Complex* pc = new Complex(4.2, 5.3);
    Complex* pd = new Complex[2];

    // using placement new
    Complex *pe = new (buf) Complex(2.6, 3.9);

    // use objects
    pc -> print();
    pd[0].print();
    pd[1].print();
    pe->print();

    // Release objects: actually it calls destructor of Complex class
    delete pc;
    delete [] pd;
    // No delete : Explicit call to Destructor.
    pe->~Complex();

    // segmentation error: happens when the address passed is a NULL pointer or a pointer that doesn't point to any location
    // Fine
    int i = 10;
    int *ipt = &i ;
    int *i1 = new(ipt) int(9) ;

    /* Incorrect as ip may not be a valid address(compile is ok, shows error at run time)
    int *ip;
    int *i2 = new(ip) int(4) ;
    */

    // Fine
    void *vd = &i;
    int *i3 = new(vd) int(34) ;

    /* Incorrect as x is not an address
    int x;
    int *i5 = new(x) int(3);
    */

    return 0;
}

/*
Advantages of placement new operator over new operator

1. The address of memory allocation is known before hand.
2. Useful when building a memory pool, a garbage collector or simply when performance and exception safety are paramount.
3. There's no danger of allocation failure since the memory has already been allocated, and constructing an object on a pre-allocated buffer takes less time.
4. This feature becomes useful while working in an environment with limited resources.
*/