#include<iostream>

using namespace std;

class AbstractProductA{
public:
    virtual void print()=0;
};
class AbstractProductB{
public:
    virtual void print()=0;
};

class ConcreteProductA1: public AbstractProductA{
public:
    void print() override{ cout<<"Concrete Product A1"<<endl; }
};
class ConcreteProductA2: public AbstractProductA{
public:
    void print() override{ cout<<"Concrete Product A2"<<endl; }
};
class ConcreteProductB1: public AbstractProductB{
public:
    void print() override{ cout<<"Concrete Product B1"<<endl; }
};
class ConcreteProductB2: public AbstractProductB{
public:
    void print() override{ cout<<"Concrete Product B2"<<endl; }
};

class AbstractFactory{
public:
    virtual AbstractProductA* createProductA()=0;
    virtual AbstractProductB* createProductB()=0;
};
class ConcreteFactory1: public AbstractFactory{
public:
    AbstractProductA* createProductA() override { return new ConcreteProductA1; }
    AbstractProductB* createProductB() override { return new ConcreteProductB1; }
};
class ConcreteFactory2: public AbstractFactory{
public:
    AbstractProductA* createProductA() override { return new ConcreteProductA2; }
    AbstractProductB* createProductB() override { return new ConcreteProductB2; }
};

int main(){
    ConcreteFactory1 pFactory1;
    ConcreteFactory2 pFactory2;

    AbstractProductA* pA1 = pFactory1.createProductA();
    pA1->print();

    AbstractProductB* pB1 = pFactory2.createProductB();
    pB1->print();

    return 0;
}

