#include<iostream>
#include<vector>

using namespace std;

class Flyweight{
public:

    virtual ~Flyweight(){}
    virtual void Operation()=0;
};
class ConcreteFlyweight: public Flyweight{
public:
    void Operation() override {cout<<"Concrete Flyweight"<<endl;}
};
class UnsharedConcreteFlyweight: public Flyweight{
public:
    void Operation() override {cout<<"UnsharedConcreteFlyweight"<<endl;}
};

class FlyweightFactory{
private:
    vector<pair<int,Flyweight*>> _pool;
public:
    Flyweight* getFlyweight(int key){
        for(auto flyweight: _pool){
            if(flyweight.first == key) {
                cout<<"Found flyweight "<<flyweight.second<<endl;
                return flyweight.second;
            }
        }
        Flyweight* newFlyweight = new ConcreteFlyweight();
        _pool.push_back(make_pair(key, newFlyweight));
        cout<<"Created new flyweight "<<newFlyweight<<endl;
        return newFlyweight;
    }
};

int main(){
    FlyweightFactory fFactory;
    Flyweight* flyweight = fFactory.getFlyweight(1);
    flyweight = fFactory.getFlyweight(1);
    flyweight->Operation();

    flyweight = fFactory.getFlyweight(2);
    flyweight = fFactory.getFlyweight(2);

    delete flyweight;

    return 0;
}
