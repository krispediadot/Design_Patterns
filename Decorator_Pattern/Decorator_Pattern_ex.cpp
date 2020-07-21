#include<iostream>

using namespace std;

class Computer{
public:
    virtual ~Computer(){}
    virtual int getSpecScore()=0;
};
class ComputerA: public Computer{
public:
    int getSpecScore() override {
        return 10;
    }
};

class Decorator: public Computer{
public:
    virtual ~Decorator(){}
    virtual int getSpecScore()=0;
    virtual int apply(int score)=0;
};
class CPU: public Decorator{
private:
    Computer* computer;
    int apply(int score) override {return 4*score;}
public:
    CPU(Computer* c): computer(c){}
    int getSpecScore() override {
        return apply(computer->getSpecScore());
    }
};
class GPU: public Decorator{
private:
    Computer* computer;
    int apply(int score) override{return 2*score;}
public:
    GPU(Computer* c): computer(c){}
    int getSpecScore() override{
        return apply(computer->getSpecScore());
    }
};

int main(){
    Computer *c = new ComputerA();
    Computer *CPUdeco = new CPU(c);
    Computer *GPUdeco = new GPU(c);
    Computer *multiDeco = new GPU(new CPU(new ComputerA()));

    cout<<"[Default Computer]: "<<c->getSpecScore()<<endl;
    cout<<"[CPU deco Computer]: "<<CPUdeco->getSpecScore()<<endl;
    cout<<"[GPU deco Computer]: "<<GPUdeco->getSpecScore()<<endl;
    cout<<"[CPU & GPU Deco Computer]: "<<multiDeco->getSpecScore()<<endl;

    delete c;
    delete CPUdeco;
    delete GPUdeco;
    delete multiDeco;

    return 0;
}
