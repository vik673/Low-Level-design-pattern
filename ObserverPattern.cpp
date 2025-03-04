#include<iostream>
#include<vector>

// Purpose : Allows objects (Observers) to be notified of changes in another objcet (subject).
// Direct communication between subject and observers.

class Observer
{
   public:
     virtual void update(const std::string& messsage) = 0;
};

class Subject
{
    private:
    std::vector<Observer*> observers;
    std::string message;

    public:
    void attach(Observer* observer)
    {
        observers.push_back(observer);
    } 
    void notify()
    {
        for(Observer *observer : observers)
        {
            observer->update(message);
        }
    }

    void setMessage(const std::string &msg)
    {
        message = msg;
        notify();
    }
};

//Concrete Observer
class ConcreteObserver : public Observer
{
    public:
      void update(const std::string &message) override
      {
        std::cout << "Received Message: " << message << std::endl;
      }
};

int main()
{
    Subject subject;
    ConcreteObserver observer;
    subject.attach(&observer);
    subject.setMessage("Hello, Observer");
    return 0;
}
