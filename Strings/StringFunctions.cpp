// examples of some commonly used string functions
#include <iostream>
#include <string>
using namespace std;

int main() {
    // string comparison: == or compare()
    string str1 = "apple";
    string str2 = "banana";
    string str3 = "apple";
    cout << "str1 == str2 : " << (str1 == str2) << endl;
    cout << "str1.compare(str2) : " << str1.compare(str2) << endl;
    cout << "str1 == str3 : " << (str1 == str3) << endl;
    cout << "str1.compare(str3) : " << str1.compare(str3) << endl; // for compare(): if equal, it returns 0
                                                             // if str1 > str2, it returns a value > 0 大小由字母决定，
                                                             // if str1 < str2, it returns a value < 0 apple<banana, cpple>banana

    // convert std::string to C String(array of characters): c_str()
    string str = "C++";
    const char* cstr = str.c_str();
    cout << endl << "After converting to C strings: " << cstr << endl;
    cout << cstr[0] << endl;

    return 0;
}