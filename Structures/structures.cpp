#include <stdio.h>

// Two steps to create a structure
// step 1: structure definition(variable can't be initialized inside the structure because no memory is allocated in the declaration)
struct Student {
    char name[50];
    int age;
    float grade;
}s3, s4; // creating structure varibles with 0 or NULL

// structures can be passed to functions
// it's recommended to pass it as a pointer to avoid copying a large amount of data
void increment(struct Student s, struct Student* sp){
    s.age++;
    sp->age++;
}

// typedef for structures: this keyword is used to define an alias for the already existing datatype
// can use typedef to define new shorter name for the structure(sometimes increases the length and complexity of the code)
typedef struct {
    int a;
} str1;
// Another way of using typedef with structures
typedef struct {
    int x;
} str2;

// nested structures
struct child {
    int x;
    char c;
};
struct parent {
    int a;
    struct child b;
};

int main() {
  
    // step 2: Declaring and initializing a structure variable
    struct Student s1 = {"Rahul",20, 18.5}; // Initialization using initializer list
  	struct Student s2 = {.age = 18, .name ="Vikas", .grade = 22}; // initialization using designated initializer list
    struct Student s5; // default initialization(will have garbage values)
    
    printf("s1 : %s\t%d\t%.2f\n", s1.name, s1.age, s1.grade);
    printf("s2: %s\t%d\t%.2f\n", s2.name, s2.age, s2.grade);
    printf("s3 : %s\t%d\t%.2f\n", s3.name, s3.age, s3.grade); 
    printf("s5 : %s\t%d\t%.2f\n", s5.name, s5.age, s5.grade); 
    s5 = {0}; // all members not explicitly initialized are zero-initialized
    printf("s5 after declared with an initializer: %s\t%d\t%.2f\n", s5.name, s5.age, s5.grade); 

    // copy structure
    struct Student s1c = s1;
    printf("s1c : %s\t%d\t%.2f\n", s1c.name, s1c.age, s1c.grade);

    // passing structures to a function
    increment(s1, &s1c);
    printf("s1 age: %d\n", s1.age); // s1.age unchanged as it's the copy that is passed to the function
    printf("s1c age: %d\n", s1c.age);

    // Creating structure variables using new names
    str1 var1 = { 20 };
    str2 var2 = { 314 };
    printf("var1.a = %d\n", var1.a);
    printf("var2.x = %d\n", var2.x);

    // nested structures example
    struct parent p = { 25, 195, 'A' };
    printf("p.a = %d\n", p.a);
    printf("p.b.x = %d\n", p.b.x); // Accessing and printing nested members: str_parent.str_child.member;
    printf("p.b.c = %c", p.b.c);


    return 0;
}

/* size of structures: technically should be the sum of the sizes of its members, but may not be true for most of the cases because of
strcture padding: adding multiple empty bytes in the structure to naturally align the data members in the memory. 
                  it's done to minimize the CPU read cycles to retrieve different data members in the structure
in the cases we need to pack the structure tightly by removing the empty bytes, we can use structure packing:
using #pragma pack(1)
or
using __attribute((pack))__
*/

/* C structures are used for the following:
1. The structure can be used to define the custom data types that can be used to create some complex data types such as dates, time, complex numbers, etc. which are not present in the language.
2. It can also be used in data organization where a large amount of data can be stored in different fields.
3. Structures are used to create data structures such as trees, linked lists, etc.
4. They can also be used for returning multiple values from a function.
*/