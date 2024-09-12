
#ifndef CAT_CPP
#define CAT_CPP

#include <iostream>
#include <string>
#include "Animal.hpp"

class Cat : public Animal
{
    public:
    Cat();
    Cat(std::string type);
    ~Cat();
};
#endif
