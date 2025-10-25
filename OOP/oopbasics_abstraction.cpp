// Abstraction: the process of hiding the implementation details and only showing the essential details/features to the user
// allow to focus on what an object does rather than how it does it
// in C++, abstraction is achieved using abstract class(classes that have at least one pure virtual function)

// in the example below, abstraction = exposing a minimal interface(accelarate, brake, startEngine) and hiding the concrete implementation in Car
#include <iostream>
using namespace std;

// Abstract class Vehicle
class Vehicle {
public:

    virtual ~Vehicle() = default;

    // Abstract methods 
    virtual void accelerate() = 0;
    
    // pure virtual function
    virtual void brake() = 0;       

    void startEngine() {
        cout << "Engine started!" << endl;
    }
};

class Car : public Vehicle {
public:

    // Implement abstract methods
    void accelerate() override {
        cout << "Car: Pressing gas pedal..." << endl;
    }

    void brake() override {
        cout << "Car: Applying brakes..." << endl;
        
    }
};

int main() {
    
    // Create object using pointer to abstract class
    Vehicle* myCar = new Car();  
    myCar->startEngine();
    myCar->accelerate();
    myCar->brake();

    delete myCar; 
    return 0;
}