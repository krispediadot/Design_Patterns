#include<iostream>

using namespace std;

class Singleton{
    static Singleton* instance;
public:
    static Singleton* getInstance(){
        if(instance == nullptr){
            instance = new Singleton;
        }
        return instance;
    }
    void print(){ cout<<"Singleton Instance"<<endl; }
};

Singleton* Singleton::instance = nullptr;

int main(){
    Singleton* pSingleton;
    pSingleton->getInstance()->print();

    return 0;
}
