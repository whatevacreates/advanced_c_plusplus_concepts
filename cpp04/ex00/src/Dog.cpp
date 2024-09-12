#include "../headers/Animal.hpp"
#include "../headers/Dog.hpp"

Dog::Dog() : Animal()
{
	Animal::setType("Dog");
	std::cout << "Dog default constructor called." << std::endl;
	return ;
}

Dog::Dog(std::string type) : Animal(type)
{
	std::cout << "Dog: parametrerized constructor called." << std::endl;
	return ;
}

Dog::~Dog()
{
	std::cout << "Dog destructor is called." << std::endl;
	return ;
}

void Dog::makeSound(void) const
{
	std::cout << "Dog is howling ... " << std::endl;
}