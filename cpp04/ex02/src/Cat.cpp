#include "../headers/A_Animal.hpp"
#include "../headers/Cat.hpp"
#include "../headers/Utils.hpp"

Cat::Cat() : Animal()
{
	_type = "Cat";
	_catIdea = "😼 I want to go fishing MIAU MIAU";
	_catBrain = new Brain(_catIdea);
	std::cout << COLOR_FASHION_BLUE << "≽^•⩊•^≼ Cat default constructor called." << RESET << std::endl;
	return ;
}

Cat::Cat(std::string idea)
{
	std::cout << COLOR_FASHION_BLUE << "≽^•⩊•^≼ Cat: parametrerized constructor called." << RESET << std::endl;
	_catIdea = idea;
	return ;
}

Cat::~Cat()
{
	delete(_catBrain);
	std::cout << COLOR_FASHION_BLUE << STRIKE << "≽^•⩊•^≼ Cat destructor is called." << RESET << std::endl;
	return ;
}

void Cat::makeSound(void) const
{
	std::cout << COLOR_FASHION_BLUE << "≽^•⩊•^≼ Little sweeeeet meow meow ... " << RESET << std::endl;
}

Cat::Cat(const Cat& other)
{
	*this = other;
}

Cat& Cat::operator=(const Cat& other)
{
	if(this != &other)
	{
		this->_type = other._type;
	}

	return *this;
}

void Cat::printIdeas() const
{
	_catBrain->printIdeas();
}