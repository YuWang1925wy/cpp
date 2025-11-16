#include <iostream>
#include <string>

class Entity
{
    public:
        Entity()
        {
            std::cout << "Created Entity!" << std::endl;
        }
        ~Entity()
        {
            std::cout << "Destroyed Entity!" << std::endl;
        }

};

/** This function is gonna fail because it creates an array on the stack */
// int* CreateArray()
// {
//     int array[50];
//     return array;
// }

/** This function is gonna work because it creates an array on the heap */
int* CreateArray()
{
    int* array = new int[50];
    return array;
}

class ScopedPtr
{
    private:
        Entity* m_Ptr;
    public:
        ScopedPtr(Entity* ptr)
            :m_Ptr(ptr)
        {

        }

        ~ScopedPtr()
        {
            delete m_Ptr;
        }
};

int main(){

    int* a = CreateArray();

    {
        Entity s; // creat an object on the stack, get destroyed when the program goes out of scope
        Entity* h = new Entity(); // create an object on the heap, destroyed when the program ends(not when it goes out of scope)
        ScopedPtr e = new Entity(); // when it goes out of scope, e got destroyed, and due to the "delete" in ScopedPtr's destructor, Entity got destroyed
    }

    std::cin.get();
}