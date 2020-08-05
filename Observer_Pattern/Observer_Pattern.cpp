#include<iostream>
#include<vector>
#include<string>
#define SIZE 20

using namespace std;

class IObserver{
public:
    virtual void update(string cmd, string name)=0;
};
class ConcreteObserver: public IObserver{
public:
    string name;
    ConcreteObserver(string name): name(name){}
    void update(string cmd, string name) override{
        cout<<"== Alert =="<<endl;
        cout<<"To: "<<this->name<<endl;
        cout<<cmd<<endl;
    }
};
class ISubject{
public:
    virtual ~ISubject(){}
    virtual void add(ConcreteObserver* newObserver)=0;
    virtual void remove(ConcreteObserver* newObserver)=0;
    virtual void notify(string cmd, string name)=0;
};
class ConcreteSubject: public ISubject{
    vector<ConcreteObserver*> list;
public:
    void add(ConcreteObserver* newObserver) override {
        list.push_back(newObserver);
        notify("Add", newObserver->name);
    }
    void remove(ConcreteObserver* observer) override {
        int index=0;
        for(int i=0; i<list.size(); i++){
            if(list[i]==observer){
                index = i;
                break;
            }
        }
        for(int i=index; i<list.size()-1; i++){
            list[i] = list[i+1];
        }
        list.resize(list.size()-1);
        cout<<"== Del =="<<endl;
        notify("Del", observer->name);
    }
    void notify(string cmd, string name) override {
        for(int i=0; i<list.size(); i++)
            list[i]->update(cmd, name);
    }
};

int main(){
    ConcreteSubject* subject = new ConcreteSubject();

    ConcreteObserver* observerA = new ConcreteObserver("A");
    ConcreteObserver* observerB = new ConcreteObserver("B");
    ConcreteObserver* observerC = new ConcreteObserver("C");
    ConcreteObserver* observerD = new ConcreteObserver("D");

    subject->add(observerA);
    subject->add(observerB);
    subject->add(observerC);
    subject->add(observerD);

    //subject->notify("DO IT RIGHT NOW!");

    subject->remove(observerA);

    //subject->notify("DO IT RIGHT NOW!");

    return 0;
}
