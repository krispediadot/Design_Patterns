#include<iostream>
#include<map>

using namespace std;

// Flyweight
class Character{
public:
    virtual ~Character(){}
    virtual void Display(int fontSize)=0;
};

// ConcreteFlyweight1
class CharacterA: public Character{
private:
    char symbol;
    int width;
    int height;
    int fontSize;
public:
    CharacterA(){
        symbol='A';
        width=100;
        height=80;
        fontSize=0;
    }
    void Display(int fontSize) override {
        fontSize = fontSize;
        cout<<symbol<<"(fontsize "<<fontSize<<")"<<endl;
    }
};
// ConcreteFlyweight2
class CharacterZ: public Character{
private:
    char symbol;
    int width;
    int height;
    int fontSize;
public:
    CharacterZ(){
        symbol='Z';
        width=100;
        height=80;
        fontSize=0;
    }
    void Display(int fontSize) override {
        fontSize=fontSize;
        cout<<symbol<<"(fontsize "<<fontSize<<")"<<endl;
    }
};
// FlyweightFactory
class CharacterFactory{
private:
    map<char, Character*> pool;
public:
    Character* getCharacter(char key){
        if(pool.find(key) != pool.end()) {
            cout<<"Found Character "<<pool[key]<<endl;
            return pool[key];
        }
        Character* character = NULL;
        switch(key){
            case 'A':
                character = new CharacterA();
                break;
            case 'Z':
                character = new CharacterZ();
                break;
        }
        pool[key] = character;
        cout<<"Create Character "<<pool[key]<<endl;
        return pool[key];
    }
};

int main(void){
    string sentence = "AAZZ";
    int fontSize = 10;

    CharacterFactory* cFactory = new CharacterFactory();

    for(auto c: sentence){
        fontSize++;
        Character* character = cFactory->getCharacter(c);
        character->Display(fontSize);
    }

    delete cFactory;

    return 0;
}
