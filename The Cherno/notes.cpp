#include <iostream>
#include <string>

class Example
{
public:
    Example()
    {
        std::cout << "Entity Created!" << std::endl;
    }

    Example(int y)
    {
        std::cout << "Entity created with " << y << "!" << std::endl;
    }
};

class Entity
{
private:
    std::string m_Name;
    mutable int m_DebugCount = 0; //mutable ensure we can change this variable in a function followed by const(like below)
    int m_Score;
    int m_Age;
    Example m_Example;
public:
    Entity()
        :  m_Name("Unkown"), m_Score(1), m_Example(8)
    {
    }

    Entity(const std::string& name)
        : m_Name(name), m_Example(9), m_Age(-1)
    {
    }

    Entity(int age)
        : m_Age(age), m_Example(10)
    {

    }

    const std::string& GetName() const 
    {
        m_DebugCount++;
        return m_Name;
    }

    const int& GetAge() const
    {
        return m_Age;
    }
};

void PrintEntity(const Entity& entity)
{
    // some printing work
}

int main()
{
    const Entity e;
    e.GetName();

    int x = 8;
    // = in [] means passing by value; or can use &, meaning passing by reference. Mutable ensures we can write x++ here
    auto f = [=]() mutable 
    {
        x++;
        std::cout << x << std::endl;
    };
    f(); 
    std::cout << x << std::endl; // outside lambda, x = 8 because we passed it by value

    Entity e0;
    std::cout << e0.GetName() << std::endl; // used default constructor

    Entity e1("Jay");
    std::cout << e1.GetName() << std::endl;

    Entity* e2;
    {
        Entity* entity= new Entity("Test"); // a way to create an object and allocate the momery to heaps
        e2 = entity;
        std::cout << "e2 " << entity->GetName() << std::endl; // entity is an address, using -> is same as (*entity).GetName()
    }
    delete e2; // delete e2 from heap memory, entity created in the block is destroyed when the block ends

    int* b = new int[50];
    Entity* e3 = new(b) Entity(); // allocate the memory to heap AND call the constructor; put e3 to b's address
    
    // delete e3;
    delete[] b; // when create a vector, must delete a vector

    Entity e4 = 27; // implicit conversion: because we have a constructor with input parameter with type int, we can create objects like this
    std::cout << e4.GetAge() << std::endl;
    // if we don't want implicit conversion happens, we can write "explicite" at the beginning of the constructors
    // if we have a function(like above PrintEntity), we can even write "PrintEntity(27)", and 27 will be converted to Entity type

    std::cin.get();
}
