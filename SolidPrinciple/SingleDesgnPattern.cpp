#include<iostream>
#include<string>

// A class should have only one responsibility.

class User
{
    std::string name;
    int age;
    public:
     User(const std::string &name, int age) : name(name), age(age){ }
     std::string getName() const {return name;}
     int getAge() const {return age;}
};

class UserRepository
{
   public:
   void saveToDatabase(const User &user)
   {
    std::cout <<"Saved user" << user.getName() << " to the database." << std::endl;
   }
};

int main()
{
    User user("Alice", 30);
    UserRepository repositary;
    repositary.saveToDatabase(user);
    return 0;
}

