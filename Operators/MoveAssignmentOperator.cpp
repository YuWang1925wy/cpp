// move assignment is a way to transfer resources, e.g. memory, files, from one object to another without copying them
#include <iostream>
#include <vector> // for std::move
#include <utility>

int main() {

    std::vector<int> a = {1, 2, 3, 4};
    std::vector<int> b;

    // move assignment: b takes ownership of a without copying
    b = std::move(a); // = is doing the assignment, std::move() casts a to an rvalue
    std::cout << "a.size() = " << a.size() << "\n";
    std::cout << "b.size() = " << b.size() << "\n";

    for (int i = 0; i < 4; i++) std::cout << b[i] << " ";
    std::cout << "\n";
    // for (int i = 0; i < 4; i++) std::cout << a[i] << " "; will throw segmentation error

    return 0;

}