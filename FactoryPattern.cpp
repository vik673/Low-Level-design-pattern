#include<iostream>
#include<string>


// Factory pattern
// factory pattern is creational design pattern that provides an interface for craeting objects in a superclass
// but allows subclasses to decide which alss to instantiate. It centralize object craetion logic, promoting loose
// coupling between classes.


// Key component
// Product: Interface/abstract class defining the object type.
// concrete product: Classes implemneting the product interface.
// Factory: Class responsible for craeting object based on input.


// Decoupling : Clent code doesn't need to know concrete classes(e. Circle, Square).
// Centralized Control : Object creation logic is in one place( the factory).
// Extensible : Easy to add new products(e.g. Triangle) without breaking existing code.


// When to Use
// When object creation involes complex logic(e.g. configuration-based instantiation).
// When you want to reuse existing objects instead of creating new ones.
// When the code needs to work with multiple interchangeable classes.


//Create shapes(circle,square) using factory
// product interface
class Shape
{
    public:
    virtual void draw() = 0;
    virtual ~Shape() {};
};

class Circle : public Shape{
public:
  void draw() override{
    std::cout << "Drawing a circle\n";
  }
};

class Square : public Shape{
    public:
     void draw() override{
        std::cout << "Drawing a Square\n";
     }
};

class ShapeFactory
{
    public:
      static Shape* createShape(const std::string& type)
      {
        if(type == "Circle") return new Circle();
        else if(type == "Square") return new Square();
        else return nullptr;
      }
};

int main()
{
    //Client code
    Shape* circle = ShapeFactory::createShape("Circle");
    Shape* square = ShapeFactory::createShape("Square");

    circle->draw();
    square->draw();

    delete circle; // output : Drawing a circle
    delete square; // output : drawing a square

    return 0;
}
