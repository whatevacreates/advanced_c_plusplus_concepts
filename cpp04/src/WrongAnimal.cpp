#include "../headers/WrongAnimal.hpp"

WrongAnimal::WrongAnimal():_type("WrongAnimal"),_sound("Random Wrong animal sound.")
{
    std::cout << "WrongAnimal: default constructor is called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type):_type(type), _sound("")
{
    std::cout << "WrongAnimal: Parameterized constructor is called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor is called." << std::endl;
    return;
}

void WrongAnimal::setType(std::string type)
{
   _type = type;
}

std::string WrongAnimal::getType(void)const
{
    return _type;
}

void WrongAnimal::setSound(std::string sound)
{
    _sound = sound;
}

std::string WrongAnimal::getSound(void)const
{
    return _sound;
}

void WrongAnimal::makeSound() const
{
    //std::string sound = getSound();
    //std::string type = getType();
    std::cout << _type << " makes the sound: " << _sound << std::endl;
}