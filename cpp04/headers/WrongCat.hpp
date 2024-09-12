
#ifndef WRONGCAT_CPP
#define WRONGCAT_CPP

#include <iostream>
#include <string>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:
    WrongCat();
    WrongCat(std::string type);
    ~WrongCat();

    void makeSound()const;
};

#endif
