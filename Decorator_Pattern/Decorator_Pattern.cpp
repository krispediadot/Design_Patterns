#include<iostream>
using namespace std;

class Component{
public:
    virtual ~Component(){}
    virtual void Operation()=0;
};
class ConcreteComponent: public Component{
public:
    void Operation() override {cout<<"Concrete Component"<<endl;}
};

class Decorator: public Component{
public:
    virtual ~Decorator(){}
    virtual void Operation()=0;
    virtual void AddBehavior()=0;
};
class ConcreteDecoratorA: public Decorator{
private:
    Component* component;
    void AddBehavior() override {cout<<"Behavior A"<<endl;}
public:
    ConcreteDecoratorA(Component* c): component(c){}
    void Operation() override {
        component->Operation();
        AddBehavior();
    }
};
class ConcreteDecoratorB: public Decorator{
private:
    Component* component;
    void AddBehavior() override{cout<<"Behavior B"<<endl;}
public:
    ConcreteDecoratorB(Component* c): component(c){}
    void Operation() override {
        component->Operation();
        AddBehavior();
    }
};

int main(){
    Component *c = new ConcreteComponent();
    Component *decoA = new ConcreteDecoratorA(c);
    Component *decoB = new ConcreteDecoratorB(c);
    Component *multiDeco = new ConcreteDecoratorB(new ConcreteDecoratorA(new ConcreteComponent()));

    cout<<"=== 1st opearation ==="<<endl;
    c->Operation();
    cout<<"=== 2nd opearation ==="<<endl;
    decoA->Operation();
    cout<<"=== 3rd opearation ==="<<endl;
    decoB->Operation();
    cout<<"=== 4th opearation ==="<<endl;
    multiDeco->Operation();

    delete c;
    delete decoA;
    delete decoB;
    delete multiDeco;

    return 0;
}
