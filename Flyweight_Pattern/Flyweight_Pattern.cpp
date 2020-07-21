#include<iostream>
#include<map>

using namespace std;

class Flyweight{
public:
    virtual ~Flyweight(){}
    virtual void Operation(string extrinsicState)=0;
};
class ConcreteFlyweight: public Flyweight{
public:
    void Operation(string extrinsicState) override {cout<<"Concrete Flyweight "<<extrinsicState<<endl;}
};
class UnsharedConcreteFlyweight: public Flyweight{
public:
    void Operation(string extrinsicState) override {cout<<"UnsharedConcreteFlyweight "<<extrinsicState<<endl;}
};

class FlyweightFactory{
private:
    map<int, Flyweight*> pool;
public:
    Flyweight* getFlyweight(int key){
        if(pool.find(key) != pool.end()) {
            cout<<"Found flyweight "<<pool[key]<<endl;
            return pool[key];
        }

        Flyweight* newFlyweight = new ConcreteFlyweight();
        pool[key] = newFlyweight;
        cout<<"Created new flyweight "<<newFlyweight<<endl;
        return pool[key];
    }
};

int main(){
    FlyweightFactory* fFactory = new FlyweightFactory();
    Flyweight* flyweight = fFactory->getFlyweight(1);
    flyweight = fFactory->getFlyweight(1);
    flyweight->Operation("extrinsic1");
    flyweight->Operation("extrinsic2");
    cout<<endl;
    flyweight = fFactory->getFlyweight(2);
    flyweight = fFactory->getFlyweight(2);
    flyweight->Operation("extrinsic2");

    delete fFactory;
    delete flyweight;

    return 0;
}
