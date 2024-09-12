#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

//#include "Utils.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("DiamondTrap_clap_name"), FragTrap(),
	ScavTrap()
{
	std::cout << "DiamondTrap default constructor called." << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"),
	FragTrap(), ScavTrap()
{
	setName(name);
	setEnergy(ScavTrap::getEnergy());
	setHits(FragTrap::getHits());
	setDamage(FragTrap::getDamage());
	std::cout << "DiamondTrap parameterized constructor called." << std::endl;
	return ;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor is called." << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "I am " << getName() << "!" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}
