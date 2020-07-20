#include<iostream>

using namespace std;

class Strategy{
public:
    virtual ~Strategy() {}
    virtual void AlgorithmInterface() = 0;
};
class ConcreteStrategyA: public Strategy{
public:
    void AlgorithmInterface() override {
        cout<<"Processed by Strategy A"<<endl;
    }
};
class ConcreteStrategyB: public Strategy{
public:
    void AlgorithmInterface() override {
        cout<<"Processed by Strategy B"<<endl;
    }
};
class ConcreteStrategyC: public Strategy{
public:
    void AlgorithmInterface() override {
        cout<<"Processed by Strategy C"<<endl;
    }
};
class Context{
    Strategy* m_pStrategy;
public:
    Context(): m_pStrategy(nullptr) {}
    ~Context() {if(m_pStrategy) delete m_pStrategy;}
    void changeStrategy(Strategy* pStrategy){
        if(m_pStrategy) delete m_pStrategy;
        m_pStrategy = pStrategy;
    }
    void ContextInterface() {
        m_pStrategy->AlgorithmInterface();
    }
};
int main(){
    Context* pContext = new Context();
    pContext->changeStrategy(new ConcreteStrategyA());
    pContext->ContextInterface();

    pContext->changeStrategy(new ConcreteStrategyB());
    pContext->ContextInterface();

    pContext->changeStrategy(new ConcreteStrategyC());
    pContext->ContextInterface();
    delete pContext;
}
