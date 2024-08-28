#include "Zombie.h"

int	main(void)
{
	Zombie	*heap;

	heap = newZombie("Heap");
	randomChump("Stack");
	delete (heap);
	return (0);
}
