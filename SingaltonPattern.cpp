#include<iostream>

// Sigleton Pattern is a creational design pattern that ensures a class has only one instance and provides a
// global acces point to that instance. It is commonly used for resource that should be shared across an appplication
// (e.g. cionfiguration manager, Logging systems, database connections).

// Key Component
// 1. private Constructor : Prevent direct instantiation.
// 2. static Instance : Holds the single iinstance of the clas.
// 3. Static Access Method : Provides global access to the instance.

class Singalton
{
    private:
    //private constructor to prevent the direct instantiation
    Singalton(){}

    //Delete copy constructor and assignment operator
    Singalton(const Singalton&) = delete;
    Singalton& operator =(const Singalton&) = delete;

    //static instance(thread-safe)
    static Singalton& getInstance()
    {
        static Singalton instance; // Created once(Lazy insitialization)
        return instance;
    }

    public:
       void showMessage()
       {
        std::cout <<"Hello from Singalton\n";
       }

       // Public access method
       static Singalton& instance()
       {
        return getInstance();
       }
};

int main()
{
    //Access the ingalton instance
    Singalton& s1 = Singalton::instance();
    Singalton& s2 = Singalton::instance();

    s1.showMessage();
    std::cout << (&s1 == &s2) << std::endl;

    return 0;
}

