|Copy constructor |	Assignment operator |
|It is called when a new object is created from an existing object, as a copy of the existing object	|This operator is called when an already initialized object is assigned a new value from another existing object. |
|It creates a separate memory block for the new object.	|It does not automatically create a separate memory block or new memory space. However, if the class involves dynamic memory management, the assignment operator must first release the existing memory on the left-hand side and then allocate new memory as needed to copy the data from the right-hand side.|
|It is an overloaded constructor.	|It is a bitwise operator. |
|C++ compiler implicitly provides a copy constructor, if no copy constructor is defined in the class.|	A bitwise copy gets created, if the Assignment operator is not overloaded. |
|Syntax:

className(const className &obj) {

// body 

}
|
Syntax: 

className obj1, obj2;

obj2 = obj1;|