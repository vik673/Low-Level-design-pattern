#include<iostream>

// Purpose: provide a surrogate to control acess to another object

class Image{
    public:
       virtual void display() =0;
};

//Real subject
class RealImage : public Image
{
    private:
    std::string filename;

    public:
    RealImage(const std::string &filename) : filename(filename)
    {
        loadFromDisk();
    }

    void display() override 
    {
        std::cout <<"Displaying " << filename << std::endl;
    }

    void loadFromDisk()
    {
        std::cout <<"Loading " << filename << " From disk" << std::endl;
    }
};

//Proxy
class ProxyImage : public Image{
    private:
     RealImage *realImage;
     std::string filename;

     public:ProxyImage(const std::string &filename) : filename(filename), realImage(nullptr){}

     void display() override{
        if(realImage == nullptr)
        {
            realImage = new RealImage(filename);
        }
        realImage->display();
     }
};
int main()
{
    Image *image = new ProxyImage("Test.jpg");
    image->display(); // load and display the image
    image->display(); // Uses cached Image
    return 0;
}