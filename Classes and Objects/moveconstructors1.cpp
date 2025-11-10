// Reason to use move constructors: transfer resources without making a copy. useful when working with temporary objects or large data

#include <iostream>
#include <vector>
using namespace std;

class Copy {
    private:
        int* data;
    public:
        Copy(int v) {
            data = new int(v);
            cout << "Constructor called for " << *data << endl;
        }

        // copy constructor
        Copy(const Copy& o) : Copy{*o.data} { // Copy{*o.data} is a delegating constructor
            cout << "Copy constructor called - Deep copy for " << *o.data << endl;
        }

        ~Copy() {
            if (data != nullptr) {
                cout << "Destructor is called for " << *data << endl;
            } else {
                cout << "Destructor is called on nullptr" << endl;
            }
            delete data;
        }

        void display() {
            cout << "data:" << *data << endl;
        }
};

class Move {
    private:
        int* data;
    public:
        Move(int v) {
            data = new int(v);
            cout << "Constructor is called for " << *data << endl;
        }

        // copy constructor
        Move(const Move& o) : Move{*o.data} {
            cout << "Copy constructor called - Deep copy " << *o.data << endl;
        }

        // move constructor
        Move(Move&& o) : data{ o.data }{
            cout << "Move constructor called for " << *o.data << endl;
            o.data = nullptr;
        }

        ~Move() {
            if (data != nullptr) {
                cout << "Destroying " << *data << endl;
            } else {
                cout << "Destructor called on nullptr\n"; 
            }
            delete data;
        }

        void display() {
            cout << "data = " << *data << endl;
        }

};

int main() {
    {
    vector<Copy> vec1;

    vec1.push_back(Copy{1});
    vec1.push_back(Copy{2});
    vec1[0].display();
    }
    /* output:
    Constructor called for 1                        // temporary Copy{1} for first push_back
    Constructor called for 1                        // triggered by the delegatio constructor in copy constructor
    Copy constructor called - Deep copy for 1       // vec1 copies the temporary {1} into its internal storage
    Destructor is called for 1                      // destroy the temporary {1}
    Constructor called for 2                        // temporary Copy{2} for second push_back
    Constructor called for 2                        // 
    Copy constructor called - Deep copy for 2       // vec1 copies the temporary {2}
    Constructor called for 1                        // as std::vector must reallocate to increase capacity, it needs to move {1} to a new place
    Copy constructor called - Deep copy for 1       // vec1 copies {1} into new place
    Destructor is called for 1                      // destroy the temporary {1}
    Destructor is called for 2                      // destroy the temporary [2]    
    Destructor is called for 2                      // leaving the scope, {2} inside vec1 is destroyed  
    Destructor is called for 1                      // leaving the scope
    */
    getchar();
    {
    vector<Move> vec2;

    vec2.push_back(Move{1});
    vec2.push_back(Move{2});
    vec2[0].display();
    }
    /* output:
    Constructor is called for 1                 // temporary Move{1} for first push_back
    Move constructor called for 1               // move into vec2
    Destructor called on nullptr                // destroy the temporary Move{1}
    Constructor is called for 2                 // temporary Move{2} for second push_back
    Move constructor called for 2               // move into vec2
    Constructor is called for 1                 // to reallocate Move{1}, which is not a temporary variable anymore, so copy constructor is called, which triggers the delegation constructor
    Copy constructor called - Deep copy 1       // copy Move{1} into the new address
    Destroying 1                                // destroy the temporary Move{1} created for copying    
    Destructor called on nullptr                // destroy temporary Move{2}, which has been moved into the vector
    data = 1
    Destroying 2                                // leaving the scope    
    Destroying 1                                // leaving the scope
    */

    return 0;
}