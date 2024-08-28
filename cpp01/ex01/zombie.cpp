#include "Zombie.h"

Zombie::Zombie()
{
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << name << ": is destroyed!" << std::endl;
	return ;
}

void Zombie::announce(void)
{
	std::cout << name << ": is created" << std::endl;
}

void Zombie::setName(std::string name)
{
	this->name = name;
}