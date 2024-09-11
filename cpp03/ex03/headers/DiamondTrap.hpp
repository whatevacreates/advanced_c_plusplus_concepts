#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"
# include "Utils.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
  private:
	std::string _name;

  public:
	DiamondTrap();
	DiamondTrap(std::string name);
	~DiamondTrap();

	void whoAmI();
	// overriding ScavTrap attack method // heyword override in c++11
	void attack(const std::string &target);
};

void	runGame(void);
int		attacks_loop(int attacks, DiamondTrap &attacker, DiamondTrap &target);
void	checkNumber(std::string str, int *num);
int		randomInt(int a, int b);

#endif