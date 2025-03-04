#include<iostream>


// Subtype must be subsitutable for their 
// base type.
class Bird
{
    public:
    virtual void eat()= 0;
    virtual ~Bird(){}
};

class  FlyingBird : public Bird{
    public:
         virtual void fly() = 0;
};

class Sparrow : public FlyingBird
{
    public:
      void eat() override { std::cout << "Sparrow eats seeds."<< std::endl;}
      void fly() override { std::cout << "Sparrow Files" << std::endl;}
};

class Peguin :public Bird
{
    public:
    void eat() override {std::cout<< "Peguin eats fish" << std::endl;}
};

int main()
{
    Sparrow sparrow;
    Peguin penguin;

    // Sparrow eats seeds.
    // Sparrow files.
    sparrow.eat();
    sparrow.fly();
    
    //Peguin eats fish.
    penguin.eat();

    return 0;
}