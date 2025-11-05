// Any constructor that can be called with a single argument works as a conversion constructor, 
// which means it can also be used for implicit conversion to the class being constructed
#include <iostream>
using namespace std;

class Point
{
  private:
    int x, y;

  public:
    Point(int i = 0, int j = 0)
    {
        x = i;
        y = j;
        cout << "Constructor called." << endl;
        cout << "object address: " << this << endl;
    }
    void print()
    {
        cout << "x = " << x << ", y = " << y << '\n';
    }
    Point* getAddr(){
        return this;
    }
};

int main()
{
    Point t(20, 20);
    t.print();
    Point* ptr = t.getAddr();
    t = 30; // invoke conversion constructor -> temporary Point(30,0)
            // then compiler assigns Point(30,0) to t, and destroys the temporary Point(30,0)
    t.print();
    cout << "First constructed object address: " << ptr << endl;
    cout << "Current object address: " << t.getAddr() << endl;
    return 0;
}