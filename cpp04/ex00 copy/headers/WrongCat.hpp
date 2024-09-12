#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
    WrongCat();                           // Constructor
    ~WrongCat();                          // Destructor

    void makeSound() const;               // Non-virtual function (No polymorphism)
};

#endif
