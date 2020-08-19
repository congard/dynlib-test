#include "Animal.h"

#include <iostream>

extern "C" Animal* create_object() {
    return new Animal;
}

extern "C" void destroy_object(Animal* object ) {
    delete object;
}

Animal::Animal() {
    m_voice = "I'm just animal...";
}

void Animal::voice() {
    std::cout << m_voice << "\n";
}
