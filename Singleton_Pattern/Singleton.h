class Singleton {
private:
    static Singleton* instance;
public:
    Singleton();
    ~Singleton();
    static Singleton* getInstance();
    void print();
};
