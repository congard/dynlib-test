#include "Cat.h"

#include <iostream>

extern "C" Cat* create_object() {
    return new Cat;
}

extern "C" void destroy_object(Cat* object ) {
    delete object;
}

Cat::Cat() {
    m_voice = "Meow!";
}

void Cat::voice() {
    std::cout << "I'm Cat! ";
    Animal::voice();
}
