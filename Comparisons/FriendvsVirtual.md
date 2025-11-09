| **Friend Function** | **Virtual Function** |
|----------------------|----------------------|
| It is a non-member function that usually has private access to a class’s representation. | It is a base class function that can be overridden by a derived class. |
| It is used to access private and protected members of a class. | It ensures that the correct function is called for an object, no matter what expression is used to make the function call. |
| It is declared outside the class scope using the `friend` keyword. | It is declared within the base class and redefined by a derived class using the `virtual` keyword. |
| It gives non-member functions access to hidden members of a class. | It enables dynamic linkage or late binding of functions. |
| Supports sharing class information that was previously hidden, providing a way to bypass data hiding restrictions in C++, and can access members without inheritance. | Supports object-oriented programming, ensures function overriding, and enables polymorphism. |
| It can access private members of a class even though it is not a member of that class. | It is primarily used to implement runtime polymorphism. |
