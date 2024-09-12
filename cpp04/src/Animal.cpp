#include "../headers/Animal.hpp"

Animal::Animal():_type("Animal"),_sound("Random animal sound.")
{
    std::cout << "Animal: default constructor is called" << std::endl;
}

Animal::Animal(std::string type):_type(type), _sound("")
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

void Animal::setSound(std::string sound)
{
    _sound = sound;
}

std::string Animal::getSound(void)const
{
    return _sound;
}

void Animal::makeSound() const
{
    std::string sound = getSound();
    std::string type = getType();
    std::cout << type << " makes the sound: " << sound << std::endl;
}