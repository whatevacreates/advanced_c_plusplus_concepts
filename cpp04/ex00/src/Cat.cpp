#include "../headers/Animal.hpp"
#include "../headers/Cat.hpp"

Cat::Cat() : Animal()
{
	Animal::setType("Cat");
	std::cout << "Cat default constructor called." << std::endl;
	return ;
}

Cat::Cat(std::string type) : Animal(type)
{
	std::cout << "Cat: parametrerized constructor called." << std::endl;
	return ;
}

Cat::~Cat()
{
	std::cout << "Cat destructor is called." << std::endl;
	return ;
}

void Cat::makeSound(void) const
{
	std::cout << "Little sweeeeet meow meow ... " << std::endl;
}