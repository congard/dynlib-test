#ifndef DYNLIB_TEST_DOG_H
#define DYNLIB_TEST_DOG_H

#include "Animal.h"

class Dog: public Animal {
public:
    Dog();

    void voice() override;
};

#endif //DYNLIB_TEST_DOG_H
