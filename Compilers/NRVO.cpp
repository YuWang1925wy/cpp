#include <iostream>
using namespace std;

class GfG {
    public:
        GfG(){ cout << "Default construcotr called" << endl; }
        GfG(const GfG&) {
            cout << "Copy construcotr called" << endl;
        }
};

GfG func(){
    GfG g;
    return g; // NRVO example: instead of creating a local return object and then copying/moving it to the caller, 
              // the object is constructed directly in the caller’s storage
}

int main() {
    GfG G = func();
    return 0;
}