// memory leak: the memory allocated for a particular task remains allocated after it's no longer needed
// reason why it happens: C++ doesn't have automatic garbage collection. any memory dynamically allocated needs to be freed manually
// e.g. when you use new but not delete

/* Consequences of Memory Leakage
1. Resource depletion, reduced performance: Leaked memory is not available for other parts of the program or 
other programs running on the computer. Program and even the whole system if leaks are significant. More of a
problem in programs that run for a long time(like servers)
2. Program crashes: if program keeps leaking memory, it might eventually use up all the available RAM, which makes
the program unstable and start behaving erratically, or crash entirely
*/

/*Example of using Valgrind to detect memory leak
1. Compile the program file using the below command in your terminal:
g++ -g -o memory_leak memory_leak.cpp
2. Now run the valgrind tool to detect the memory leaks using the following command:
valgrind --leak-check=full ./memory_leak
*/
#include <iostream>
using namespace std;

// function to allocation memory fynamically for an array
void createLeak()
{
    int* arr = new int[10];
}

int main()
{
    createLeak();
    cout << "Program finished." << endl;
    return 0;
}

/*Detecting memory leaks
Manual Techniques
Carefully review code to ensure every new has a corresponding delete.
Use consistent memory management patterns, such as pairing allocations and deallocations in the same scope or module.
Implement custom memory management functions that log allocations and deallocations to track memory usage.
Use smart pointers whenever possible.
Properly Follow the RAII (Resource Acquisition Is Initialization) principle whenever possible in your codes.
Implement proper exception handling to ensure resources are released.
Conduct regular code reviews focusing on memory management.
Write comprehensive unit tests, including tests for memory leaks.

Tools
Valgrind, AddressSanitizer(Asan), LeakSanitizer(LSan)
*/

