#include<iostream>
#include<map>
#include<vector>
#include<functional>

using namespace std;

// Purpose : Decouple publishers and subscribers via a message broker.
// Uses Broker to decouple the publisher and sucriber.


class PubSubServer
{
    private:
      map<string, vector<function<void(const string&)>>> subscribers;

      public:

      
      void subscribe(const string &topic, const function<void(const string&)> &callback){
        subscribers[topic].push_back(callback);
      }

      void publish(const string &topic, const string &message)
      {
        if(subscribers.find(topic) !=  subscribers.end())
        {
            for(auto &callback : subscribers[topic])
            {
                callback(message);
            }
        }
      }

};

int main()
{
    PubSubServer server;

    //Subscriber 1
    server.subscribe("news", [](const string &msg)
    {
        cout<< "Subscriber 1 received" << msg << endl;
    });

    //Subscriber 2
    server.subscribe("news", [](const string &msg)
    {
        cout<< "Subscriber 2 received" << msg << endl;
    });

    server.publish("news", "Breaking news : C++ is awsome");
    return 0;
}