#include "Zombie.h"

int	main(void)
{
	int		N;
	Zombie	*zombies;

	N = 2;
	zombies = zombieHorde(N, "Zombie");
	for (int i = 0; i < N; i++)
	{
		zombies[i].announce();
	}
	delete[] zombies;
	return (0);
}
