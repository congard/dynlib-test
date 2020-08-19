#ifndef DYNLIB_TEST_CAT_H
#define DYNLIB_TEST_CAT_H

#include "Animal.h"

class Cat: public Animal {
public:
    Cat();

    void voice() override;
};

#endif //DYNLIB_TEST_CAT_H
