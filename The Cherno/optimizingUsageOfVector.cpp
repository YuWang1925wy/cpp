// Important rules of optimization: knowing your environment
// Def. Know the Environment: how do things work, what do I need to do exactly, what should happen
// Cause of slow operation: constantly relocate memory
#include <iostream>
#include <string>
#include <vector>

struct Vertex
{
    float x, y, z;
    Vertex(float x, float y, float z)
        :x(x), y(y), z(z)
    {
    }

    Vertex(const Vertex& vertex)  // copy constructor
        :x(vertex.x), y(vertex.y), z(vertex.z)
    {
        std::cout << "Copied!" << std::endl;
    }
};

int main()
{
    std::vector<Vertex> vertices;
    vertices.push_back({1,2,3}); // constructing Vertex in stack frame of current main function, no copy in this step(constructing with the first constructor)
                                 // and then put it from the main function to the memory that the vector has allocated, by copying(so this is where copy happens )
    std::cin.get(); // will see 1 "Copied!" here
    vertices.push_back({4,5,6}); // 1 copy for vector resizing, 1 copy for pushing new Vertex into the vector
    std::cin.get(); // will see 1+2 "Copied!"
    vertices.push_back(Vertex(7,8,9));
    std::cin.get(); // will see 1+2+3 "Copied!"

    // optimization strategy 1: reduce resizing
    std::vector<Vertex> vertices2;
    vertices2.reserve(3); // reserve memory for 3 Vertex object
    vertices2.push_back(Vertex(1,2,3));
    vertices2.push_back(Vertex(7,8,9));
    vertices2.push_back(Vertex(7,8,9));
    std::cin.get(); // will see 3 "Copied!" in total, because we don't need to resize here

    // optimization strategy 2: construct Vertex in place(to the memory address of the vector) instead of construct and copy to vector
    std::vector<Vertex> vertices3;
    vertices3.reserve(3); // reserve memory for 3 Vertex object
    vertices3.emplace_back(1,2,3); // construct Vertex objects with the following parameters in place in our actual vector memory
    vertices3.emplace_back(7,8,9);
    vertices3.emplace_back(7,8,9);
    std::cin.get(); // will see 0 extra "Copied!" (Wow!!!)
}