#include <iostream>
#include <memory> // for smart pointers, template-based
using namespace std;

class Rectangle {
    int length;
    int breadth;

public:
    Rectangle(int l, int b) {
        length = l;
        breadth = b;
    }
    int area() { return length * breadth; }
};

int main() {
    // 1. Memory leak
    int* ptr0;
    int i = 1;
    
    while (i <= 1) {
        
        // Create a variable in heap memory using pointer
        int* ptr = new int;
        cout << "ptr: " << ptr << endl;
        // memory leak because ptr to this allocation will be lost, but allocated block is not freed
        ptr0 = ptr;
        i++;
    }
    cout << "ptr0: " << ptr0 << endl; // allocated memory is not freed

    cout << endl;
    // 2. unique_ptr: only one pointer can point to one address
    unique_ptr<Rectangle> P1(new Rectangle(1,1));
    cout << "Calling P1 area: " << P1->area() << endl;
    cout << "P1: " << P1 << endl;

    unique_ptr<Rectangle> P2;
    // Copy the address of P1 into P2, P1
    P2 = std::move(P1);
    cout << "Calling P2: " << P2->area() << endl;
    cout << "P2: " << P2 << endl;
    cout << "P1(after transfer ownership): " << (P1==nullptr) << endl; // P1 is a NULL pointer now

    cout << endl;
    // 3. shared_ptr: more than one pointer can point to same object at a time
    shared_ptr<Rectangle> P3(new Rectangle(2, 2));
    cout << "Calling P3 area: " << P3->area() << endl;

    shared_ptr<Rectangle> P4;
    
    // P3 and P4 are pointing to same object
    P4 = P3;
    cout << "Calling P4 area: " << P4->area() << endl;
    cout << "P3: " << P3 << endl;
    cout << "P4: " << P4 << endl;
    cout << "Counts: " << endl;
    cout << P3.use_count() << endl;
    cout << P4.use_count() << endl;

    cout << endl;
    // 4. weak_ptr: non-owning reference to an object(similar to shared_ptr,但use_count不计weak_ptr)
    weak_ptr<Rectangle> P5(P3);
    cout << P5.use_count() << endl; // doesn't increase the total number of pointers

    return 0;
}