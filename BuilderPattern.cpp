#include<iostream>
#include<string>

using namespace std;

// Builder pattern is a creational design pattern that seprates the constructor of a complex object from its 
// representation. It allows you to create object step-by-step, configure different variations of an object, and
// produce immutable objects. It is especially useful when an object has many optional parameter.

// key component: 
// Product : the complex object to be created
// Builder : Abstract interface for creating parts of the product.
// Concrete builder : Implements the builder interface to construct the product.
// Director : Orchestrate te construction process.

// Key benefit:
// Immutable objects :Once built, the objects state can not be modified.
// Readable code: Method chaining make configuration clear.
// Flexibility : Different builders can craete variation of the same object.

// When to use
// When an object has many optional parameters.
// When you want yo enforce a step-by-step construction process.
// When you need to create different configuration of an object.

// product : Complex object to be built
class Computer
{
    private:
    std::string ram;
    std::string storage;
    std::string cpu;

    // Private constructor (Only builder can create instances)
    Computer(const std::string& ram, const std::string& storage, const std::string& cpu): ram(ram), storage(storage), cpu(cpu) {}

    public:
    friend class ComputerBuilder; // Grand builder access

    void displaySpecs() const{
        std::cout <<"Ram: " << ram << "\nStorage: " << storage
        <<"\nCPU: " << cpu << "\n";
    }
};

//Builder : constructs the computer object step-by-step
class ComputerBuilder
{
    private:
    std::string ram;
    std::string storage;
    std::string cpu;
    public:
     ComputerBuilder& setRAM(const std::string& ram)
     {
        this->ram = ram;
        return *this; // Enable the method chaining
     }

     ComputerBuilder& setStorage(const std::string& storage)
     {
        this->storage =  storage;
        return *this;
     }

     ComputerBuilder& setCpu(const std::string& cpu)
     {
        this->cpu = cpu;
        return *this;
     }
    
      Computer build()
      {
        return Computer(ram, storage, cpu);
      }
};

int main()
{
   ComputerBuilder computerBuilder;
   Computer c1 =  computerBuilder.setRAM("10KB").setStorage("20KB").setCpu("13KB").build();
   c1.displaySpecs();
   return 0;
}