// a string is an array of characters terminated by a special character '\0'
// this null character marks the end of the string, essential for proper string manipulation
// C does not have a built-in string data type, strings are implemented as arrays of char
#include <stdio.h>
#include <string.h> // for strcpy

// as strings are character arrays, we can pass strings to functions in the same way we pass an array to a function
void printStr(char str[]) {
    printf("%s", str);
}

int main() {

    char str[] = "Geeks"; // Internally, this creates an array like { 'G', 'e', 'e', 'k', 's', '\0'} '\0' is automatically added
    printf("The string is: %s\n", str);

    // access the characters: []
    printf("%c\n", str[0]);

    // update: [] or strcpy(destination array, source string)
    str[0] = 'R';
    printf("After updating: %s\n", str);
    char str1[50]; // ensure destination has enough space
    strcpy(str1, str);
    printf("str1: %s\n", str1);

    // string length: strlen(), it returns size_t type
    printf("String length: %zu\n", strlen(str));

    // string input: scanf()
    char str2[5];
    printf("Enter a string <= 4 characters: ");  // prompt
    scanf("%4s", str2);                           // read at most 4 chars + '\0'
    printf("You entered: %s\n", str2);

    // eat the leftover '\n'
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }

    char str3[20];
    printf("Now you can input text with spaces: ");
    scanf("%[^\n]", str3); // using scanset in scanf to read until new line
    printf("You entered: %s\n", str3);

    // string input 2: fgets(), it reads the entire line, including spaces, until it encounters a newline
    while ((c = getchar()) != '\n' && c != EOF) { }     // eat the leftover '\n'
    char str4[20];
    printf("Now you can input text with spaces again: ");
    fgets(str4, 20, stdin);
    printf("You entered: %s", str4);

    // passing strings to functions
    printf("Passing strings to a function: ");
    printStr(str4);

    // similar to arrays, in C, we can create a character pointer to a string
    char* ptr = str;
    while (*ptr != '\0') {
        printf("%c ", *ptr);
        ptr++;
    }
    
    // string literals: use const for safety
    const char* ptr1 = "Hello World!"; // the right hand side is a string literal, stored in read-only section of memory
    printf("\n%s\n", ptr1);

    return 0;
}