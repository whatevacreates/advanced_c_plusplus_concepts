#include "../headers/Animal.hpp"
#include "../headers/Utils.hpp"

Animal::Animal() : _type("Animal"), _sound("Random animal ROAAARRS  𓃬")
{
	std::cout << PASTEL_LAVENDER << BOLD << "𓃬  Animal: default constructor is called" << RESET << std::endl;
}
Animal::Animal(std::string type) : _type(type), _sound("Random animal sound.")
{
	std::cout << PASTEL_LAVENDER << "𓃬  Animal: Parameterized constructor is called" << RESET << std::endl;
}

Animal::~Animal()
{
	std::cout << PASTEL_LAVENDER << BOLD << "𓃬  Animal destructor is called." << RESET << std::endl;
	return ;
}

Animal::Animal(const Animal &other) : _type(other.getType())
{
	std::cout << PASTEL_LAVENDER << "𓃬  Animal: Copy constructor is called" << RESET << std::endl;
	*this = other;
}

Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
	{
		_type = other.getType();
	}
	return (*this);
}

void Animal::setType(std::string type)
{
	_type = type;
}

std::string Animal::getType(void) const
{
	return (_type);
}

void Animal::makeSound() const
{
	std::string type = getType();
	std::cout << BOLD << PASTEL_LAVENDER << BOLD << type << " makes the ♪♪♪ " << _sound << RESET << std::endl;
}
