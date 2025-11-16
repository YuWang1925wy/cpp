// standard template library: filled with container types
// std::vector : can resize when the content exceed the current size
#include <iostream>
#include <string>
#include <vector>

struct Vertex
{
    float x, y, z;
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex)
{
    stream << vertex.x << " , " << vertex.y << " , " << vertex.z;
    return stream;
}

void Function(const std::vector<Vertex>& vertices) // when vector is an input, use const and & to make sure we don't make copies
{

}

int main()
{
    Vertex* vertices[5]; // an array with fixed size

    std::vector<Vertex> vertices2; // this vector can resize if needed
    vertices2.push_back({1,2,3}); // changing size
    vertices2.push_back({4,5,6});
    vertices2.push_back({7,8,9});

    for (int i = 0; i < vertices2.size(); i++)
        std::cout << vertices2[i] << std::endl;

    std::cin.get(); 

    vertices2.erase(vertices2.begin() + 1); // remove the second element of the vector

    // simpler way to iterate
    for (Vertex& v : vertices2) // using & so that we don't make copies
        std::cout << v << std::endl;

    std::cin.get();

    vertices2.clear(); // set the vector size to 0

}