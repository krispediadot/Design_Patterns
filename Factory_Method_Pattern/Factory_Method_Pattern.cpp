#include<iostream>

using namespace std;

class Product{
public:
    virtual void print()=0;
    virtual ~Product() {}
};
class ConcreteProduct: public Product{
public:
    void print() override {
        cout<<"ConcreteProduct"<<endl;
    }
};
class Creator{
protected:
    virtual Product* FactoryMethod()=0;
public:
    virtual ~Creator() {}
    Product* AnOperation(){return FactoryMethod();}
};
class ConcreteCreator: public Creator{
private:
    Product* FactoryMethod(){return new ConcreteProduct;}
};

int main(){
    ConcreteCreator pCreator;

    Product* pProduct = pCreator.AnOperation();
    pProduct->print();

    return 0;
}

