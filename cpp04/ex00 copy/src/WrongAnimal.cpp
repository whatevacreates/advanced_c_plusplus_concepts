#include "../headers/WrongAnimal.hpp"
#include "../headers/Utils.hpp"


WrongAnimal::WrongAnimal() : _type("WrongAnimal") 
{
    std::cout <<PASTEL_LIME  << BOLD << "WrongAnimal constructor called" <<RESET << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    
    std::cout <<PASTEL_LIME  << BOLD << "WrongAnimal destructor called" << RESET << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    if(this != &other)
    {
        this->_type = other._type;
    }
    return *this;
}
WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
    *this = other;
}

std::string WrongAnimal::getType() const {
    return _type;
}

void WrongAnimal::makeSound() const {
    std::cout <<PASTEL_LIME  << BOLD << _type << " ▶︎ •၊၊||၊|။||||| 0:10 <wrong animal sound>" << RESET << std::endl;
}