// Nested class: a class declared in another enclosing class
// it's a member, so has the same access as any other member
// the members of an enclosing class have no special access to members of a nested class
#include<iostream>
using namespace std;

class Enclosing {      
    private:   
        int x = 42;
   
   // start of Nested class declaration 
    class Nested {
        int y = 0;

        public:   
            void NestedFun(Enclosing *e) {
                cout << e->x << endl;  // fine: nested class can access private members of Enclosing class
            }       
    };

    public:
        void demo() {
            Nested n;
            n.NestedFun(this);
        }
 
}; 

int main()
{   
    Enclosing e;
    e.demo();
    return 0;
}

// Nested class is used when a helper "type" belongs to one class and you want to keep it tightly scoped and hidden