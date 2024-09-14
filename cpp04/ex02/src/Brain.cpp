#include "Brain.hpp"
#include "Utils.hpp"

Brain::Brain()
{
	for (int i = 0; i < 101; i++)
	{
		_ideas[i] = "Nobody's idea nr " + std::to_string(i);
	}
	std::cout << ITALIC << PASTEL_CREAM << "🧠 Brain: default copy contructor called." << RESET << std::endl;
	return ;
}

Brain::Brain(std::string idea)
{
	for (int i = 0; i < 101; i++)
	{
		_ideas[i] = idea + " nr" + std::to_string(i);
	}
	std::cout << ITALIC << PASTEL_CREAM << "🧠 Brain: default copy contructor called." << RESET << std::endl;
	return ;
}

Brain::Brain(const Brain &other)
{
	std::cout << ITALIC << PASTEL_CREAM << "🧠 Brain: default copy contructor called." << RESET << std::endl;
	*this = other;
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << ITALIC << PASTEL_CREAM << "🧠 Brain: default copy contructor called." << RESET << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 101; i++)
		{
			_ideas[i] = other._ideas[i];
		}
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << ITALIC << PASTEL_CREAM << STRIKE << "🧠 Brain: default copy contructor called." << RESET << std::endl;
	return ;
}

void Brain::printIdeas() const
{
	for (int i = 0; i < 101; i++)
	{
		std::cout << ITALIC << PASTEL_CREAM << _ideas[i] << RESET << std::endl;
	}
}