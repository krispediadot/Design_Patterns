#include<iostream>

using namespace std;

class AbstractClass{
private:
    virtual void subMethod() = 0;
    void intro() { cout<<"START"<<endl; }
public:
    void templateMethod(){
        intro();
        subMethod();
    }
};
class ConcreteClass1: public AbstractClass{
public:
    void subMethod() override{
        cout<<"ConcreteClass1"<<endl;
    }
};
class ConcreteClass2: public AbstractClass{
public:
    void subMethod() override{
        cout<<"ConcreteClass2"<<endl;
    }
};

int main(){
    AbstractClass* test = new ConcreteClass1;
    test->templateMethod();

    delete test;

    test = new ConcreteClass2;
    test->templateMethod();

    delete test;

    return 0;
}

