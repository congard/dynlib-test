#include "Dog.h"

#include <iostream>

extern "C" Dog* create_object() {
    return new Dog;
}

extern "C" void destroy_object(Dog* object ) {
    delete object;
}

Dog::Dog() {
    m_voice = "Gaw!";
}

void Dog::voice() {
    std::cout << "I'm Dog! ";
    Animal::voice();
}
