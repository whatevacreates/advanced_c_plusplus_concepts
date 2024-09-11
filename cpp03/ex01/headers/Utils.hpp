#ifndef UTILS_HPP
# define UTILS_HPP

# include "ClapTrap.hpp"
#include "ScavTrap.hpp"
# include <cmath>
# include <limits>
# include <random>

void	runGame(void);
int		attacks_loop(int attacks, ScavTrap &attacker, ScavTrap &target);
void	checkNumber(std::string str, int *num);
int		randomInt(int a, int b);
#endif