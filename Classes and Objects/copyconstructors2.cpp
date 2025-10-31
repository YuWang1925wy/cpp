// Example of creating a copy constructor that does deep copy
#include <iostream>
using namespace std;

class String
{
  private:
    char *s;
    int size;

  public:
    String(const char *str) // parameterized constructor
    {
        cout << "Constructing an object..." << endl;
        size = strlen(str);
        s = new char[size + 1];
        strcpy(s, str);
    }
    ~String() // destructor
    {
        cout << "Destroying an object..." << endl;
        delete[] s;
    }
    String(const String &old_str) // copy constructor that performs deep copy
    {
        cout << "Constructing an object by copying..." << endl;
        size = old_str.size;
        s = new char[size + 1];
        strcpy(s, old_str.s);
    }
    void print()
    {
        cout << &s << endl;
        cout << s << endl;
    }

    void change(const char *str)
    {
        delete[] s;
        size = strlen(str);
        s = new char[size + 1];
        strcpy(s, str);
    }

};

int main()
{
    String str1("GeeksQuiz");

    // Create str2 from str1
    String str2 = str1; // copy constructor is called
    str1.print();
    str2.print();

    // Update the str2 object
    str2.change("GeeksforGeeks");

    str1.print();
    str2.print();
    return 0;
}