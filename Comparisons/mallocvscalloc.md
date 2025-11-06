| malloc() | calloc() |
|-----------|-----------|
| malloc() is a function that creates one block of memory of a fixed size. | calloc() is a function that assigns a specified number of blocks of memory to a single variable. |
| malloc() only takes one argument. | calloc() takes two arguments. |
| malloc() is faster than calloc. | calloc() is slower than malloc(). |
| malloc() has high time efficiency. | calloc() has low time efficiency. |
| malloc() is used to indicate memory allocation. | calloc() is used to indicate contiguous memory allocation. |
| Syntax: `void* malloc(size_t size);` | Syntax: `void* calloc(size_t num, size_t size);` |
| malloc() does not initialize the memory to zero. | calloc() initializes the memory to zero. |
| malloc() does not add any extra memory overhead. | calloc() adds some extra memory overhead. |
