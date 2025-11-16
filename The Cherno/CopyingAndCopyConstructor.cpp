// situations we need to make a copy: only want to read data, or modify the existing object
// unnecessary copying wastes performance
#include <iostream>

struct Vector2
{
    float x, y;
};

class String
{
    private:
        char* m_Buffer;
        unsigned int m_Size;
    public:
        String(const char* string)
        {
            m_Size = strlen(string);
            m_Buffer = new char[m_Size+1]; // because memcpy doesn't have null termination character, if we don't do "m_Size+1", the output will have some extra stuff coming out
            memcpy(m_Buffer, string, m_Size); // or we can use strcpy(), which includes the null termination character
            m_Buffer[m_Size] = 0; // manually adding a null termination
        }

        // default copy constructor(shallow copy: copy the members as they are, not the actually memory)
        // String(const String& other)
        //     :m_Buffer(other.m_Buffer), m_Size(other.m_Size)
        // {
        // }

        // another way of implementing default copy constructor
        // String(const String& other)
        // {
        //     memcpy(this, &other, sizeof(String));
        // }

        // way to delete the default copy constructor
        // String(const String& other) = delete;

        // creating a deep copy constructor by ourselves
        String(const String& other)
            :m_Size(other.m_Size) // this is an integer, shallow copy works
        {
            m_Buffer = new char[m_Size + 1]; // intialize a new address
            memcpy(m_Buffer, other.m_Buffer, m_Size + 1); // here because we are copying from a String object, 
                                                          // we know that it has the null termination(cuz we add it), 
                                                          // so no need to do extra stuff on null termination
        }

        ~String()
        {
            delete[] m_Buffer;
        }

        char& operator[](unsigned int index)
        {
            return m_Buffer[index];
        }

        friend std::ostream& operator<<(std::ostream& stream, const String& string); // "friend" allows the outside function to access the private members

};

std::ostream& operator<<(std::ostream& stream, const String& string) // allow std to output object String(?)
{
    stream << string.m_Buffer;
    return stream;
}

int main()
{
    int t = 2;
    int z = t; // z makes a copy of t, when we modify t, a doesn't change

    Vector2* a = new Vector2();
    Vector2* b = a; // b makes a copy of the address, a is an address
    b->x = 2; // b and a point to the same memory, so when b changes, the memory a points to changes
    std::cout << "a = " << (*a).x << std::endl;
    std::cin.get();

    String string = "Jay";
    String second = string; // shallow copy case: copy the object string to another memory address, 

    second[0] = 'Y'; // the output changes for both object if we don't have the deep copy constructor

    std::cout << string << std::endl; // but since m_Buffer is a char pointer, the pointers of string and second actually point to the same memory
    std::cout << second << std::endl; // so when we run this program, the destructor run twice, trying to free the same memory twice, causing program to crash
    std::cin.get();

}