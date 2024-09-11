#include "Utils.hpp"

// Default constructor
ClapTrap::ClapTrap() : _hits(10), _energy(10), _damage(0)
{
	std::cout << "ClapTrap Default constructor called." << std::endl;
}

// Parameterized constructor
ClapTrap::ClapTrap(std::string name) : _name(name), _hits(10), _energy(10),
	_damage(0)
{
	setName(name);
	setDamage(0);
	setEnergy(10);
	setHits(10);
	std::cout << "ClapTrap Parameterized constructor called." << std::endl;
}

// Destructor
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called." << std::endl;
}

// Attack method
void ClapTrap::attack(const std::string &target)
{
	setEnergy(_energy - 1);
	setHits(_hits - 1);
	if (_energy <= 0)
	{
		std::cout << _name << " has no energy left and died." << std::endl;
		return ;
	}
	std::cout << _name << ": attacks " << target << std::endl;
	std::cout << _name << ": energy levels: " << _energy << std::endl;
	std::cout << _name << ": hits left: " << _hits << std::endl;
}

// Take damage method
void ClapTrap::takeDamage(unsigned int amount)
{
	setDamage(_damage + amount);
	std::cout << _name << " takes " << amount << " damage. Current damage: " << _damage << std::endl;
}

// Be repaired method
void ClapTrap::beRepaired(unsigned int amount)
{
	setDamage(_damage - amount);
	setEnergy(_energy - amount);
	setHits(_hits + amount);
	if (_energy <= 0)
	{
		std::cout << _name << " has no energy left and died." << std::endl;
		return ;
	}
	std::cout << _name << " heals:::::::::::::::::::::::" << std::endl;
	std::cout << "Damage: " << this->getDamage() << std::endl;
	std::cout << "Hits: " << this->getHits() << std::endl;
	std::cout << "Energy: " << this->getEnergy() << std::endl;
}

// Setters
void ClapTrap::setHits(int hits)
{
	_hits = hits;
}

void ClapTrap::setEnergy(int energy)
{
	_energy = energy;
}

void ClapTrap::setDamage(int damage)
{
	_damage = damage;
}

// Getters
int ClapTrap::getHits()
{
	return (_hits);
}

int ClapTrap::getEnergy()
{
	return (_energy);
}

int ClapTrap::getDamage()
{
	return (_damage);
}

int ClapTrap::checkEnergyLevel()
{
	if (this->getEnergy() <= 0)
		return (1);
	return (0);
}

void ClapTrap::setName(std::string name)
{
	_name = name;
}

std::string ClapTrap::getName()
{
	return _name;
}