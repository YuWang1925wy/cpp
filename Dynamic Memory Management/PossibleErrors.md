### Errors Associated with Dynamic Memory

- Memory Leaks
Memory leak is a situation where the memory allocated for a particular task remains allocated even after it is no longer needed. Moreover, if the address to the memory is lost, then it will remain allocated till the program runs.

Solution: Use smart pointers whenever possible. They automatically deallocate when goes out of scope.

- Dangling Pointers
Dangling pointers are created when the memory pointed by the pointer is accessed after it is deallocated, leading to undefined behaviour (crashes, garbage data, etc.).

Solution: Initialize pointers with nullptr and assign nullptr again when deallocated.

- Double Deletion
When delete is called on the same memory twice, leading to crash or corrupted program.

Solution: assign nullptr to the memory pointer when deallocated.

- Mixing new/delete with malloc()/free()
C++ supports the C style dynamic memory allocation using malloc(), calloc(), free(), etc. But these functions are not compatible. It means that we cannot allocate memory using new and delete it using free(). Same for malloc() and delete.