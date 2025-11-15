// copy assignment operator=(const T& )
// move assignment operator=(T&& )

#include <iostream>
#include <cstring> // for strlen and strcpy

class MyString {
    private:
        char* data;
    public:
        // constructor
        MyString(const char* str = ""){
            data = new char[strlen(str) + 1];
            strcpy(data, str);
        }

        // copy and move assignment operators almost always return *this by reference, i.e. the current object itself
        // so the return type is T&
        MyString& operator=(MyString&& other){ // other is a reference parameter, it refers to an existing MyString object
            std::cout << "Move assignment called\n";

            if (this != &other) {  // this(keyword) is a pointer to the current object, so we need to take the reference of other(&other) to compare them
                // free old memory
                delete[] data;
                // steal the pointer
                data = other.data;
                // set source to null
                other.data = nullptr;
            }

            return *this; 
        }

        ~MyString() {
            delete[] data;
        }

        void print() {
            if (data)
                std::cout << data << std::endl;
            else
                std::cout << "[empty]\n";
        }

};

int main() {
    MyString s1("Hello");
    MyString s2("World");
    s1.print();
    s2.print();

    s2 = std::move(s1);
    s1.print();
    s2.print();

    return 0;
}

/* why do we need move assignment operator?
1. improves performance, it's faster than making a copy
2. reduces memory usage
3. handles temporary objects efficiently - it allows objects to take ownership of data from temporary values w/o copying
*/