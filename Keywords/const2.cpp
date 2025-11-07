// constant member functions: can not change the values of the data members of their class
// four cases:
// 1. const member func, const object -> Yes
// 2. const member func, non-const object -> Yes
// 3. non-const member func, const object -> No
// 4. non-const member func, non-const object -> Yes
#include <iostream>
using namespace std;

class Demo {
    int x;

    public:
        Demo() {}
        Demo(int v) { x = v; }

        void set_data(int a) { x = a; }

        int get_data(){
            ++x;
            return x;
        }

        int get_data_const() const; // declare const member function

        int get_data3(){
            return x;
        }
};

// define member function outside the class
int Demo::get_data_const() const {
    // can't write ++x; here like get_data()
    return x;
}

int main() {

    Demo d;
    d.set_data(10); // case 4
    cout << "d = " << d.get_data() << endl; // case 4
    cout << "d = " << d.get_data_const() << endl; // case 2

    const Demo d2(1);
    cout << "d2 = " << d2.get_data_const() << endl; // case 1
    /* will throw error
    d2.set_data(2); // case 3
    d2.get_data(); // case 3
    d2.get_data3(); // case 3
    */
   

    return 0;

}