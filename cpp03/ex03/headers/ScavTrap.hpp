#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "Utils.hpp"

class ScavTrap : virtual public ClapTrap
{
  public:
	ScavTrap();
	ScavTrap(std::string name);
	~ScavTrap();
	void guardGate();
};

#endif