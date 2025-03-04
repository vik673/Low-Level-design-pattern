#include<iostream>

// Purpose : Encapulates a request as an object.

// Command interface
class Command
{
    public:
     virtual void execute() =0;
};

// Receiver
class Light
{
    public: 
       void turnOn() {
        std::cout << "light is ON"  << std::endl;
        }
        
        void turnOff()
        {
            std::cout << "Light is OFF" << std::endl;
        }
};

//Concrete Commands
class LightOnComman : public Command
{
    private:
    Light &light;

    public:
       LightOnComman(Light &l) : light(l){}

       void execute() override
       {
        light.turnOn();
       }
};

class LightOffCommand : public Command{
    private:
    Light &light;

    public:
      LightOffCommand(Light &l) : light(l) {}

      void execute() override {
        light.turnOff();
      }
};

//Invoker
class RemoteControl
{
    private:
       Command *command;

    public:
      void setCommand(Command *cmd)
      {
        command=cmd;
      }

      void pressButton()
      {
        command->execute();
      }
};

int main()
{
    Light light;
    RemoteControl remote;
    remote.setCommand(new LightOnComman(light));
    remote.pressButton(); // Output : Light is ON.

    remote.setCommand(new LightOffCommand(light));
    remote.pressButton();

    return 0;
}