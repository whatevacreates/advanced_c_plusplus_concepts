
#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "Utils.hpp"

// Default constructor
ScavTrap::ScavTrap() : ClapTrap()
{
	setHits(100); // ScavTrap-specific initialization
	setEnergy(50);
	setDamage(20);
	std::cout << "ScavTrap default constructor called." << std::endl;
}

// Constructor with name
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	setName(name);
	setHits(100);
	setEnergy(50);
	setDamage(20);
	std::cout << "ScavTrap " << name << " constructed." << std::endl;
}

// Destructor
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called for " << this->getName() << "." << std::endl;
}

// ScavTrap  method
void ScavTrap::guardGate()
{
	std::cout << getName() << " is now in Gatekeeper mode!" << std::endl;
}
