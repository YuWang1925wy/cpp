// rule of five: if any of the below functions is defined for a class, then it's better to define all of them
// desctructor
// copy constructor
// copy assignment operator
// move constructor
// move assignment operator

// why we have rule of five: shallow copy might lead to segmentation faults when the source object is destroyed
/* Syntax:
class ClassName {
public:
    // Destructor
    ~ClassName() {
        // releasing allocated memory 
        // Make sure to add the necessary code to release any resources you've acquired, such as dynamic memory or file handles.
    }

    // Copy Constructor
    ClassName(const ClassName& other) {
        // Here's the code for the copy constructor, which performs a deep copy of the resources.
    }

    // Copy Assignment Operator
    ClassName& operator=(const ClassName& other) {
        if (this != &other) { 
           // generate a deep copy of resources
        }
        return *this;
    }

    // Move Constructor
    ClassName(ClassName&& other) noexcept //“noexcept” is not a function name but a specifier in C++, does not throw any exceptions
    { 
        // Here's the code for the move constructor, 
        // The transfer of ownership of resources.
    }

    // Move Constructor
    ClassName(ClassName&& other) noexcept //“noexcept” is not a function name but a specifier in C++, does not throw any exceptions
    { 
        // Here's the code for the move constructor, 
        // The transfer of ownership of resources.
    }
};
*/

// Example the 5 elements:
#include <iostream>
#include <utility> // for using move
using namespace std;

class ResourceManager {
    private:
        int* data;
        size_t size;
    public:
        // constructor
        ResourceManager(size_t sz = 0) 
            : data(new int[sz]), 
              size(sz)
        {
            cout << "Default constructor called.\n";
        }

        // destructor
        ~ResourceManager()
        {
            delete[] data;
            cout << "Destructor called\n";
        }

        // copy constructor
        ResourceManager(const ResourceManager& other)
            : data(new int[other.size]), // makes a deep copy to avoid double freeing the memory
              size(other.size)
        {
            copy(other.data, other.data + other.size, data);
            cout << "Copy constructor called\n";
        }

        // copy assignment operator
        ResourceManager& operator=(const ResourceManager& other)
        {
            if (this != &other) {
                delete[] data;
                data = new int[other.size];
                size = other.size;
                copy(other.data, other.data + other.size, data);
            }
            cout << "Copy assignment operator called\n";
            return *this;
        }

        // move constructor
        ResourceManager(ResourceManager&& other) noexcept
            : data(other.data), // don't need to allocate new memory like copy constructor, because the current object will own the resource
              size(other.size)
        {
            other.data = nullptr;
            other.size = 0;
            cout << "Move constructor called\n";
        }

        // move assignment operator
        ResourceManager& operator=(ResourceManager&& other) noexcept
        {
            if (this != &other) {
                delete[] data;
                data = other.data;
                size = other.size;
                other.data = nullptr;
                other.size = 0;
            }
            cout << "Move assignment operator called\n";
            return *this;
        }
};

int main() {
    ResourceManager obj1(5); // creat an object using default construcotr

    ResourceManager obj2 = obj1; // create an object using copy constructor

    ResourceManager obj3;
    obj3 = obj1; // crate an object using copy assignment operator

    ResourceManager ojb4 = std::move(obj1); // create an object using move constructor

    ResourceManager obj5;
    obj5 = std::move(obj2); // create an object with move assignment operator

    return 0;
}