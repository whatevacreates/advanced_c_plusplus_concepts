#include "WrongAnimal.hpp"
#include "Utils.hpp"

WrongAnimal::WrongAnimal():
		_type("WrongAnimal")
{
	std::cout <<PASTEL_LIME  << BOLD << "WrongAnimal default constructor called" <<RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	std::cout <<PASTEL_LIME  << BOLD << "WrongAnimal copy constructor called" <<RESET << std::endl;
	*this = src;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs)
{
	if(this == &rhs)
		return *this;
	this->_type = rhs._type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout <<PASTEL_LIME  << BOLD << "WrongAnimal destructor called" <<RESET << std::endl;
}

void	WrongAnimal::makeSound() const
{
	std::cout <<PASTEL_LIME  << BOLD << _type << " ▶︎ •၊၊||၊|။||||| 0:10 <wrong animal sound>" << RESET << std::endl;

}

std::string	WrongAnimal::getType() const
{
	return (this->_type);
}
