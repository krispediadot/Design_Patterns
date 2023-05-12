#include <iostream>
#include "Singleton.h"

Singleton* Singleton::instance = nullptr;

Singleton::Singleton() {}

Singleton::~Singleton() {}

Singleton* Singleton::getInstance() {
    if(instance == nullptr) {
        instance = new Singleton;
    }
    return instance;
}

void Singleton::print() {
    std::cout << "Singleton Instance: " << &instance << std::endl;
}
