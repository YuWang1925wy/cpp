// a sequence of bytes -> streams
// the data needed to be displayed on the screen is inserted in the standard output stream (cout) using the insertion operator(<<)
// he extraction operator (>>) is used along with the object cin for extracting the data from the input stream and store it in some variable in the program

#include <iostream>
using namespace std;

int main() {
    string name;
  
  	// while taking text as input using cin, 
    // cin stops reading input as soon as it encounters a whitespace (space, tab, or newline)
    cin >> name; // if input "Yu Wang"
  
  	// Output the entered name
    cout << "Name entered: " << name << endl; // output "Yu"

    // cerr and clog are instances of iostream class
    // cerr is un-buffered(can't store the message)
    // clog: the error is first inserted into a buffer and is stored in the buffer
    cerr << "An error occurred - cerr" << endl;
    clog << "An error occurred - clog" << endl;
    flush(clog); // flush the storage

    // switch statement
    char c = 'B';
    switch (c) {
        
    // if the input character is A then print GFG
    case 'A':
        cout << "GFG";
        break; // a control flow statement that is used to terminate the loop; continue go to next iteration

    // if the input character is B then print
    // GeeksforGeeks
    case 'B':
        cout << "GeeksforGeeks" << endl;
        break;
    default:
        
        // if the input character is invalid then print
        // invalid input
        cout << "invalid input";
    }

    // example for goto control: used to transfer the control to another part of the program
    int age = 17;
    if (age < 18) {
        
        // Execution of code go to the
        // line 15
        goto Noteligible;
    }
    else {
        cout << "You can vote!";
    }
Noteligible:
    cout << "You are not eligible to vote!\n";
    return 0;

    return 0;
}

