#include<iostream>

// Clients should not be forced to depend
// on unused interface.

class Wrorkable
{
    public:
    virtual void work() =0;
    virtual ~Wrorkable() {}
};

class Eatable
{
    public:
    virtual void eat() = 0;
    virtual ~Eatable() {}
};

class HumanWorker : public Wrorkable, public Eatable{
   public:
   void work() override { std::cout << "Human Working" << std::endl;}
   void eat() override {std::cout<< "Human Eating" << std::endl;}
};

class RobotWorker : public Wrorkable
{
    public:
    void work() override{std::cout << "Robot working" << std::endl;}
};

int main()
{
    HumanWorker human;
    RobotWorker robot;

    human.work();
    human.eat();

    robot.work();
    return 0;
}