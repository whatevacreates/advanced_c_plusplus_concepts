#include "Utils.hpp"
#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << PASTEL_TURQUOISE << ITALIC << "😼 WrongCat: default constructor called" << RESET << std::endl;
	this->_type = "WrongCat";
}

WrongCat::~WrongCat()
{
	std::cout << PASTEL_TURQUOISE << ITALIC << "😼 WrongCat: destructor called" << RESET << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &rhs)
{
	if (this == &rhs)
		return (*this);
	this->_type = rhs._type;
	return (*this);
}

WrongCat::WrongCat(const WrongCat &src)
{
	std::cout << PASTEL_TURQUOISE << ITALIC << "😼 WrongCat: copy constructor called" << RESET << std::endl;
	*this = src;
}

void WrongCat::makeSound() const
{
	std::cout << PASTEL_TURQUOISE << ITALIC << "😼 WrongCat: meow" << RESET << std::endl;
}
