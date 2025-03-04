
// Decorator design pattern is a structural design pattern that allows you to dynamiccaly add responsibilities
// to objects by wrapping them in "decorator classes. It provides a flexible alternative to subclassibng for extending functionality.
// Think of it as "Wrapping a gift" - each layer adds a new feature without altering the original object.

// Key component
// Componnt:- interface defining the base object and its operations.
// Concrete Component:- The original class implementing the component.
// Decorator:- Abstract class that wraps a component and implments its interface.
// Concrete Decorators:- Classes that add specific functionalities to the component.

// Key Features
// Dynamic Extention: Add responsibilitiesat runtime by stacking decorator.
// Open/Close Principle:- Extend Functionaliy without modifying existing code.
// Flexibility:- Mix and match decorator in any order.

// When to use
// When you need to add responsibilities to objects dynamicaaly
// When subclassing is impractical(e.g. too many combination of features)
// When you want to avoid a rigid class hierarchy( e.g. GUI toolkits, input/output streams).

// Decorating a coffee with add-on(milk, sugar)

#include<iostream>
#include<string>

// Componnet : Coffee Interface
class Coffee
{
    public:
    virtual double cost() const = 0;
    virtual std::string description() const = 0;
    virtual ~Coffee() = default;
};

//Concrete Component
class SimpleCoffee : public Coffee{
    public:
    double cost() const override { return 2.0;}
    std::string description() const override {return "Simple cpoffee";}
};
// Decorator: Abstact Wrapper for coffee
class CoffeeDecorator : public Coffee{
    protected:
    Coffee* coffee;
    public:
      CoffeeDecorator(Coffee* coffee) : coffee(coffee){}
      virtual ~CoffeeDecorator() {delete coffee;}
};

class MilkDecorator: public CoffeeDecorator {
    public:
      MilkDecorator(Coffee* coffee) : CoffeeDecorator(coffee){}

      double cost() const override {
        return coffee->cost()+0.5; // add milk cost
    }

    std::string description() const override {
        return coffee->description() + " + Milk";
    }
};

class SugarDecorator : public CoffeeDecorator
{
      public:
      SugarDecorator(Coffee* coffee) : CoffeeDecorator(coffee){}

      double cost() const override {
        return coffee->cost()+0.2; // add sugar cost
    }

    std::string description() const override {
        return coffee->description() + " + Sugar";
    }
};

int main()
{
    // Create a simple coffee and decorate it.
    Coffee* coffee = new SimpleCoffee();
    coffee = new MilkDecorator(coffee);
    coffee = new SugarDecorator(coffee);

    std::cout << "Description: " << coffee->description() << std::endl;
    std::cout << "Total cost: " << coffee->cost() << std::endl;

    delete coffee;
    return 0;
}
