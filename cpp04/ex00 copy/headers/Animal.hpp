#ifndef ANIMAL_CPP
#define ANIMAL_CPP

#include <iostream>
#include <string>

class Animal
{
    protected:
    std::string _type;
    std::string _sound;
    public:
    Animal();
    Animal(std::string type);
    Animal(const Animal& others);
    Animal& operator=(const Animal& others);

    /* The virtual keyword in C++ is used to define functions in a base class
    that can be overridden in derived classes. It enables runtime polymorphism or dynamic binding,
    meaning that the function that gets called is determined based on the type of the object at runtime,
     not the type of the pointer/reference."
     */
     
    virtual ~Animal();
    virtual void makeSound() const;
    //setters:
    void setType(std::string type);
    //getters:
    std::string getType(void) const;
    
};

#endif

