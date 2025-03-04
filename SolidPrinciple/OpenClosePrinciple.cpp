#include<iostream>

//Abstract base calss
class Shape
{
    public:
       virtual double area() const = 0;
       virtual ~Shape(){}
};

class Circle : public Shape{
    double radius;
    public:
    Circle(double r) : radius(r) {}
    double area() const override { return 3.14 * radius * radius; }
};

class Square : public Shape{
    double side;
    public:
    Square(double s) : side(s) {}
    double area() const override {return  side*side; }
};

void printArea(const Shape &shape)
{
    std::cout << "Area: " << shape.area() << std::endl;
}

int main()
{
    Circle c(5);
    Square s(4);
    printArea(c);
    printArea(s);
    return 0;
}