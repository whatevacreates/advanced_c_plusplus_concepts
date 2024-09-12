#ifndef ANIMAL_CPP
#define ANIMAL_CPP

#include <ostream>
#include <string>

class Animal
{
    protected:
    std::string type;
    public:
    Animal()
    ~Animal();


    virtual void makeSound();
};

