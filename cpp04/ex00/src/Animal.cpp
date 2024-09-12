#include "../headers/Animal.hpp"

Animal::Animal():_type("Animal"),_sound("Random animal sound.")
{
    std::cout << "Animal: default constructor is called" << std::endl;
}

Animal::Animal(std::string type):_type(type), _sound("Random animal sound.")
{
    std::cout << "Animal: Parameterized constructor is called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal destructor is called." << std::endl;
    return;
}

void Animal::setType(std::string type)
{
   _type = type;
}

std::string Animal::getType(void)const
{
    return _type;
}


void Animal::makeSound() const
{
    std::string type = getType();
    std::cout << type << " -------------makes the sound: " << _sound << std::endl;
}