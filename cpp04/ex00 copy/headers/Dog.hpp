#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
public:
    Dog();                               // Constructor
    ~Dog();                              // Destructor

    void makeSound() const;     // Override Animal's makeSound()
};

#endif
