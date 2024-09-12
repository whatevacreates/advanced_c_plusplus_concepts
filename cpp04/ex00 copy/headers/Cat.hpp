#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
public:
    Cat();                               // Constructor
    ~Cat();                              // Destructor

    void makeSound() const;     // Override Animal's makeSound()
};

#endif