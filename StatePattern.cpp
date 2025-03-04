#include<iostream>

// allows an object to change its behaviour when its internal state changes.
// Changes behaviour based on the internal state.

//state interface
class State
{
    public:
    virtual void handle() =0;
};

// Concrete States
class ConcretetateA : public State
{
  public:
   void handle() override{
    std::cout << "Handling State A" << std::endl;
   }
};

class ConcreteStateB : public State
{
    public:
    void handle() override{
        std::cout << "Handling State B" << std::endl;
    }
};


class ConcreteStateB : public State{
    public:
        void handle() override{
            std::cout << "Handling State B" << std::endl;
        }
};


//context
class Context
{
  private:
   State *state;

   public:
   Context(State *initialState) : state(initialState) {}

   void setState(State *newState)
   {
    state = newState;
   }

   void request()
   {
    state->handle();
   }
};

int main()
{
    Context context(new ConcretetateA());
    context.request();

    context.setState(new ConcreteStateB());
    context.request();

    return 0;    
}
