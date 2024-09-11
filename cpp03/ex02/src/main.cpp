#include "Utils.hpp"

int	main(void)
{
	runGame();
	return (0);
}

int	randomInt(int a, int b)
{
	std::random_device rd; // Obtain a random seed from hardware,
	// you need to "seed" the generator!
	std::default_random_engine generator(rd());
	std::uniform_int_distribution<int> distribution(a, b);
	return (distribution(generator));
}

void	runGame(void)
{
	int	attacks;

	FragTrap attacker("Attacker_FragTrap");
	FragTrap target("Target_FragTrap");
	while (1)
	{
		attacks = randomInt(1, 3);
		attacker.highFivesGuys();
		if (attacks_loop(attacks, attacker, target)
			|| attacker.checkEnergyLevel() || target.checkEnergyLevel())
			break ;
		attacks = randomInt(1, 3);
		target.highFivesGuys();
		if (attacker.checkEnergyLevel() || target.checkEnergyLevel()
			|| attacks_loop(attacks, target, attacker))
			break ;
	}
}

int	attacks_loop(int attacks, FragTrap &attacker, FragTrap &target)
{
	std::cout << "-------->> " << attacks << " attack(s) scheduled:" << std::endl;
	for (int k = 0; k <= attacks; k++)
	{
		attacker.attack("Target");
		if (k == 10)
		{
			std::cout << "Target died." << std::endl;
		}
	}
	target.takeDamage(attacks);
	target.beRepaired(attacks);
	attacker.beRepaired(attacks);

	return (0);
}