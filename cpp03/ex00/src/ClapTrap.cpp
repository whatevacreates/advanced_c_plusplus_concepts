#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _hits(10), _energy(10), _damage(0)
{
	std::cout << "Default constructor called." << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name) : _hits(10), _energy(10), _damage(0)
{
	_name = name;
	std::cout << "Parameterized constructor called." << std::endl;
	return ;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called." << std::endl;
	return ;
}

void ClapTrap::attack(const std::string &target)
{
	--_energy;
	--_hits;
	if (_energy <= 0)
	{
		std::cout << _name << " has no enegy left and died." << std::endl;
		exit(1);
	}
	std::cout << _name << ": attacks " << target << std::endl;
	std::cout << _name << ": energy levels: " << _energy << std::endl;
	std::cout << _name << ": hits left: " << _hits << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	_damage += amount;
	std::cout << "damage: " << _damage << std::endl;
	std::cout << _name << " takes damage. Current damage: " << _damage << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	_damage -= amount;
	_energy -= amount;
	_hits += amount;
	if (_energy <= 0)
	{
		std::cout << _name << " has no enegy left and died." << std::endl;
		exit(1);
	}
	std::cout << _name << " healed." << std::endl;
	std::cout << "Damage: " << _damage << std::endl;
	std::cout << "Hits: " << _hits << std::endl;
	std::cout << "Energy: " << _energy << std::endl;
}
