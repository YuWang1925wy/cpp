// allow us to define a set of named values(fixed and predetermined at the time of declaration)

#include <iostream>
using namespace std;

// enum type example:
enum roll_no {
    avinash = 68,
    shreya = 47,
    nikita = 69,
};

enum rainbow {
    violet,
    indigo,
    blue,
    green,yellow,orange,red
}colors;

enum class eyecolor:char { // set the data type as char to determine the size of the type
    blue,green,brown
}eye;

int main()
{
    enum roll_no obj;
    obj = avinash;
    cout << "The roll no  of avinash = " << obj;

    // enum type restriction 1: two enumerations cannot share the same values
    enum Gender { Male,
                  Female };

    /* enum Gender2 { Male,
            Female2 }; -> will throw error */

    Gender gender = Male;
    // Gender2 gender2 = Female; -> will throw error
    cout << "gender: " << gender << endl; 

    /* enum type restriction 2: no variable can have name same in the values in some enumeration
    int Male = 10; -> will throw error
    */

    // enum type disadvantage: enums are not type-safe
    enum Color { Red, Green };
    Color color = Red;
    if (gender == color) // will throw warning, but will compile
        cout << "gender = color" << endl;


    /*---------Enum Class Example----------------*/
    // strongly typed and strongly scoped
    enum class People { Good, Bad };
    enum class Color2 { Red, Green };
    enum class Color3 { Red, Black, White }; // two enum classes can share values

    // Variables can use enum class value name
    int White = 10;

    // enum class is type-safe, doesn't compare enumerators with different enumerations
    Color2 x = Color2::Red;
    People p = People::Good;
    
    /* gives an error, won't compile
    if (p == x) cout << "x == p" << endl;
    */

    /* enum class doesn't allow implicit conversion to int
    int y = Color3::Black; -> will throw error
    */
    cout << int(x) << endl; // fine as this is explicit conversion
    
    // enum class has more control over their underlying type
    // it may be any integral data type, e.g. char, short or unsigned int, which essentially serves to determines the size of the type
    cout << "size of enum rainbow variable: " << sizeof(colors) << endl;
    cout << "size of enum class eyecolor variable: " << sizeof(eye) << endl;

    return 0;
}