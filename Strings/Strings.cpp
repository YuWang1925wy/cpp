#include <iostream>
#include <string>
using namespace std;

int main() {

    string str = "Hello Geeks"; // 1. initializing a string

    // traversing using index, 2.1 access the characters by [] operator
    cout << "Using index: ";
    for (int i = 0; i < str.size(); i++) {
        cout << str[i];
    }
    cout << endl;

    // traversing using range-based for loop
    cout << "Using range-based for loop: ";
    for (char ch : str) {
        cout << ch;
    }
    cout << endl;

    // traversing using iterator
    cout << "Using iterator: ";
    for (auto it = str.begin(); it != str.end(); it++) {
        cout << *it;
    }
    cout << endl;

    cout << endl;
    // 2.2 access the characters with the .at() function
    cout << "Character at index 6: " << str.at(6) << endl;

    cout << endl;
    // 3. string length, time complexity O(1)
    cout << "Length using size(): " << str.size() << endl;
    cout << "Length using length(): " << str.length() << endl;

    cout << endl;
    // 4. concatenation of strings, time complexity O(n+m), n = size of string, m = size of the string to be concatenated
    string str1 = "Hello";
    string str2 = " Geeks";
    string res1 = str1 + str2;
    cout << "Concatenation using +: " << res1 << endl;
    string res2 = str1;
    res2.append(str2);
    cout << "Concatenation using append(): " << res2 << endl;

    cout << endl;
    // 5. modifying a string
    str.push_back('!'); // adding a character in the end, O(1)
    cout << "After push_back(): " << str << endl;
    str.pop_back();     // removing the last character, O(1)
    cout << "After pop_back(): " << str << endl;
    str.insert(5, " C++");      // inserting a substring at str[5], O(n)
    cout << "After insert: " << str << endl;
    str.erase(5, 4);    // erasing part of the string, O(n)
    cout << "After erase: " << str << endl;

    string text = "I like dogs.";
    text.replace(7, 4, "cats");
    cout << "After replace: " << text << endl;

    cout << endl;
    // 6. substring extraction, time complexity O(len)
    string sub1 = str.substr(0, 5); // substr(pos, len)
    cout << "substring1: " << sub1 << endl;

    cout << endl;
    // 7. searching in a string, time complexity O(n*m)
    size_t pos = str.find("Geeks");
    if (pos < str.size()) {
        cout << "\"Geeks\" found at index: " << pos << endl;
    }

    return 0;
}