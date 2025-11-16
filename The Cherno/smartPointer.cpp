#include <iostream>
#include <string>
// For smart pointers,
// when you call new, you don't have to call delete
// in many cases, you don't even have to call new
// it's essentially a wrapper around a real raw pointer

// Unique pointer: a scoped pointer; has to be the only reference to a same memory in that scope, so can't make a copy
// Shared pointer: reference counting, count references, delete when it goes to 0
#include <memory>
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
        void Print()
        {
            std::cout << "Unique pointer print is called." << std::endl;
        };

};

int main(){
    {
        std::unique_ptr<Entity> entity(new Entity()); // have to call the constructor because for unique pointer the constructor is explicit
        entity->Print();
    }
    std::cin.get();
    {
        // a slightly safer way to create object
        std::unique_ptr<Entity> entity2 = std::make_unique<Entity>(); // help constructor avoid throwing exceptions and having a pointer with no reference, which cause memory leak
    }
    std::cin.get();
    {
        std::shared_ptr<Entity> e0;
        {
            std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();

            //std::shared_ptr<Entity> sharedEntity(new Entity()); 
            // it complies but the ref count = 2: Entity constructed + shared pointer control block(when it counts references); 2 allocations in this case
            
            e0 = sharedEntity; // now ref count = 2, so when it goes out of scope, the memory won't be deleted

            std::weak_ptr<Entity> weakEntity = sharedEntity; // doesn't add on the ref count, a way to check if shared pointers are still alive
        }
        std::cin.get();
    }

    std::cin.get();
}