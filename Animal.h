#ifndef DYNLIB_TEST_ANIMAL_H
#define DYNLIB_TEST_ANIMAL_H

#include <string>

class Animal {
public:
    Animal();

    // use virtual otherwise linker will try to perform static linkage
    virtual void voice();

protected:
    std::string m_voice;
};

#endif //DYNLIB_TEST_ANIMAL_H
