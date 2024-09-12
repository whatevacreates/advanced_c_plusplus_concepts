
#include "Utils.hpp"

// Default constructor
FragTrap::FragTrap() : ClapTrap()
{
	
	setHits(100); // ScavTrap-specific initialization
	setEnergy(100);
	setDamage(30);
	std::cout << "FragTrap default constructor called." << std::endl;
}

// Constructor with name
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	setName(name);
	setHits(100);
	setEnergy(50);
	setDamage(20);
	std::cout << "FragTrap " << name << ": parameterized constructor called." << std::endl;
}

// Destructor
FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called for " << this->getName() << "." << std::endl;
}

// FragTrap  method
void FragTrap::highFivesGuys()
{
	std::cout << getName() << " is asking for HIGH FIVE!" << std::endl;
}
