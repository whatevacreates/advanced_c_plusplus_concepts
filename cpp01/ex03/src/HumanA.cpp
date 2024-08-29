#include "HumanA.h"
#include "HumanB.h"
#include "Weapon.h"

HumanA::HumanA(std::string name, Weapon &weaponRef) : name_(name),
	weaponRef_(weaponRef)
{
	return ;
}

HumanA::~HumanA()
{
	return ;
}

void HumanA::attack()
{
	std::cout << name_ << ":A attack with " << weaponRef_.getType() << std::endl;
}