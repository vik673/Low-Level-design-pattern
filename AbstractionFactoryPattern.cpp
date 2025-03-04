#include<iostream>

// Purpose: Creates families of the related/dependent objects(e.g. UI components for different OS style)
// Use case: When you need to create multiple product type that work together(e.g. Button, Checkbox for Windows/Mac).
// Key idea: Factories produce objects that are comptiable within a theme.

// Key points:
// 1. Creates families of the related products(e.g. Button, Checkbox)
// 2. More Complex(Multiple factories and products).
// 3. Add new product families(e.g. LinuxFactory).
// 4. Multiple products that must work together.

//  this is mostly used when you need to create multiple related objects(e.g. UI components for specific OS).

// Product
class Button
{
  public:
    virtual void render() = 0;
    virtual ~Button() {};
};

class WinButton : public Button
{
    public:
    void render() override{ std:: cout<< "Windows Button\n";}
};

class MacButton : public Button{
    public:
    void render() override { std::cout << "Mac Button\n";}
};

class Checkbox{
   public:
    virtual void render() = 0;
    virtual ~Checkbox(){}
};

class WinCheckbox : public Checkbox{
    public:
    void render() override{  std::cout << "Windows Checkbox\n";}
};

class MacCheckBox : public Checkbox
{
    public:
      void render() override { std::cout << "Mac Checkbox\n";}
};

class GUIFactory
{
    public:
    virtual Button* createButton() = 0;
    virtual Checkbox* createCheckbox()=0;
    virtual ~GUIFactory(){}
};

class WinFactory : public GUIFactory
{
    public:
     Button* createButton() override {return new WinButton();}
     Checkbox* createCheckbox() override{return new MacCheckBox();}
};

int main()
{
    GUIFactory* factory = new WinFactory();
    Button* button = factory->createButton();
    Checkbox* checkbox = factory->createCheckbox();

    button->render();
    checkbox->render();

    delete factory;
    delete button;
    delete checkbox;
    return 0;
}