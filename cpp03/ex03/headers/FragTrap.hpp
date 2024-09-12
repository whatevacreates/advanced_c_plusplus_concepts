#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include "ScavTrap.hpp"
#include "Utils.hpp"

class FragTrap : virtual public ClapTrap
{
  public:
	FragTrap();
	FragTrap(const FragTrap &other);
    FragTrap& operator=(const FragTrap &other);
	FragTrap(std::string name);
	~FragTrap();
	void highFivesGuys();
};

#endif