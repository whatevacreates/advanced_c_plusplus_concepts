#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "Utils.hpp"
class FragTrap : public ClapTrap
{
  public:
	FragTrap();
	FragTrap(std::string name);
	~FragTrap();
	void highFivesGuys();
};

#endif