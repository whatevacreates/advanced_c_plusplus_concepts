#include "../headers/Animal.hpp"
#include "../headers/Dog.hpp"
#include "../headers/Utils.hpp"

Dog::Dog() : Animal()
{
	_type = "Dog";
	_dogBrain = new Brain();
	std::cout << PASTEL_BROWN << "🐶  Dog: default constructor called." << RESET << std::endl;
	return ;
}

Dog::Dog(std::string type) : Animal(type)
{
	std::cout << PASTEL_BROWN << "🐶  Dog: parametrerized constructor called." << RESET << std::endl;
	return ;
}

Dog::Dog(const Dog& other)
{
	*this = other;
}

Dog& Dog::operator=(const Dog& other)
{
	if(this != &other)
	this->_type = other.getType();
	return *this;
}
Dog::~Dog()
{
	delete(_dogBrain);
	std::cout << PASTEL_BROWN << STRIKE << "🐶  Dog: destructor is called." << RESET << std::endl;
	return ;
}

void Dog::makeSound(void) const
{
	std::cout << PASTEL_BROWN << "🐶  Dog: is HOWLING ... " << RESET << std::endl;
}
