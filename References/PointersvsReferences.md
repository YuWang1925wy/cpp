|Aspect	|Reference|	Pointer|

|Definition	|A reference is an alias for an existing variable.	|A pointer is a variable that stores the memory address of another variable.|
|Initialization	|Must be initialized when declared and cannot be reassigned.	|Can be initialized later and can be reassigned to point to different objects.|
|Nullability|	Cannot be null; must always refer to an object.	|Can be null, pointing to no object (e.g., nullptr).|
|Syntax|	Uses & for declaration and accessing.	|Uses * for declaration and dereferencing, & for address-of.|
|Dereferencing	|No dereferencing required, ca be used directly like a normal variable.	|Must be dereferenced using * to access the value it points to.|
|Void Type|A reference can never be void.|A pointer can be declared as void|
|Nesting|Reference variable has only one/single level of indirection.  |A pointer variable has n-levels/multiple levels of indirection i.e. single-pointer, double-pointer, triple-pointer|
|Pointer Arithmetic|	Cannot perform arithmetic operations (e.g., increment or decrement).	|Can perform arithmetic operations (e.g., increment or decrement).|
|Use Case|	Primarily used for simpler, more readable references to variables.	|Used for more complex memory management, dynamic memory allocation, and handling arrays.|
|Example|	int& ref = x;|	int* ptr = &x;|
