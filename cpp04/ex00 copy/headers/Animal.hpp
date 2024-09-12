#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
protected:
    std::string type;

public:
    Animal();                             // Default constructor
    virtual ~Animal();                    // Virtual destructor

    std::string getType() const;          // Getter for type

    virtual void makeSound() const;       // Virtual function to be overridden in derived classes
};

#endif
