#include <cstdlib>   // std::malloc, std::realloc, std::free
#include <cstdio>    // std::printf, std::perror

int main() {
    std::size_t n = 3; // std::size_t is the unsigned integer type used for object sizes and array indexing
                       // it's the type returned by sizeof

    // Allocate space for 3 ints
    int* arr = static_cast<int*>(std::malloc(n * sizeof(int)));
    if (!arr) { std::perror("malloc failed"); return 1; }

    for (std::size_t i = 0; i < n; ++i) arr[i] = static_cast<int>(i + 1);

    std::printf("Initial:  addr=%p  size=%zu  values: ", (void*)arr, n);
    for (std::size_t i = 0; i < n; ++i) std::printf("%d ", arr[i]);
    std::printf("\n");

    // GROW to 6 ints (note: new elements are uninitialized)
    std::size_t n2 = 6;
    int* tmp = static_cast<int*>(std::realloc(arr, n2 * sizeof(int))); // syntax: T new_name = realloc(old_name, number of bytes);
    if (!tmp) {
        // On failure, 'arr' is still valid; free and exit
        std::free(arr);
        std::perror("realloc (grow) failed");
        return 1;
    }
    arr = tmp;

    // Initialize the new slots
    for (std::size_t i = n; i < n2; ++i) arr[i] = static_cast<int>((i + 1) * 10);

    std::printf("After grow: addr=%p  size=%zu  values: ", (void*)arr, n2);
    for (std::size_t i = 0; i < n2; ++i) std::printf("%d ", arr[i]);
    std::printf("\n");

    std::free(arr);
    return 0;
}
