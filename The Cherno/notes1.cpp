#include <iostream>
#include <string>

struct Vector2
{
    float x, y;
    Vector2(float x, float y)
        : x(x), y(y) {}

    Vector2 Add(const Vector2& other) const
    {
        return Vector2(x + other.x, y + other.y);
    }

    // overloading Add()
    Vector2 operator+(const Vector2& other) const
    {
        return Add(other);
    }

    Vector2 Multiply(const Vector2& other) const
    {
        return Vector2(x * other.x, y * other.y);
    }

    // overloading Multiply()
    Vector2 operator*(const Vector2& other) const
    {
        return Multiply(other);
    }

};

// defines an overloaded operator<< for outputting a Vector2 object to an output stream (e.g., std::cout)
std::ostream& operator<<(std::ostream& stream, const Vector2& other)
{
    stream << other.x << "," << other.y;
    return stream;
}

int main()
{
    Vector2 position(4.0f, 4.0f);
    Vector2 speed(0.5f, 1.5f);
    Vector2 powerup(1.1f, 1.1f);

    Vector2 result_add = position.Add(speed); 
    std::cout << "Result Add: " << result_add.x << "," << result_add.y << std::endl;

    Vector2 result_multiply = position + speed * powerup; // overload the operators by some extra work in defining the class(above)
    std::cout << "Result Multiply: " << result_multiply << std::endl;
}