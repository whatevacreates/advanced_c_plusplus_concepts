#include "Zombie.h"

Zombie	*newZombie(std::string name)
{
	Zombie	*Heap;

	Heap = new Zombie(name);
	return (Heap);
}
