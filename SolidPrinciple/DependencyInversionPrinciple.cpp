#include<iostream>
#include<string>

// Depend on abstraction, not concretions.

class Database
{
    public:
      virtual void save(const std::string &data) =0;
      virtual ~Database(){}
};

class MySql : public Database
{
    public:
         void save(const std::string &data) override
         {
            std::cout <<"MySql saved: " << data << std::endl;
         }
};

class MongoDb : public Database
{
    public:
       void save(const std::string &data)
       {
        std::cout << "MonoDB saved: " << data << std::endl;
       }
};

class Report
{
    Database &db;
    public:
    Report(Database &db) :db(db) { }
    void generate(const std::string &data) {db.save(data);}
};

int main()
{
    MySql mysql;
    MongoDb mango;

    Report report1(mysql);
    report1.generate("Sales Data");

    Report report2(mango);
    report2.generate("Log Data");
    return 0;
}