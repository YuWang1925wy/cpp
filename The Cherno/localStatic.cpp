// lifetime of a variable: how long it remains in the memory before it gets deleted
// scope of a variable: where we can access that variable
// static local variable: lifetime = entire program, scope limited to certain scope, eg. inside functions
#include <iostream>

void Function()
{
    int i = 0; // initialize i = 0 every time the function is called
    i++;
    std::cout << i << std::endl;

    static int j = 0; // initialize j when the function is called for the first time, don't create new variables in later calls
    j++;
    std::cout << "static j: " << j << std::endl;
}

class Singleton
{
    public:
        static Singleton& Get()
        {
            static Singleton instance; // if we don't use static, the variable will get destroyed when the function goes out of scope
            return instance;           // since we want to return a reference, it causes trouble when the variable is destroyed
        }                              // in this way, only the function can access the variable member in Singleton class; meanwhile we don't have to initialize it in private:

        void Hello() {}
};

int main()
{   
    Function();
    Function();
    std::cin.get();

    Singleton::Get().Hello();
    std::cin.get();
}