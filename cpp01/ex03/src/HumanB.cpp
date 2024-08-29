#include "HumanA.h"
#include "HumanB.h"
#include "Weapon.h"

HumanB::HumanB(std::string name)
{
	name_ = name;
	return ;
}

HumanB::~HumanB()
{
	return ;
}

void HumanB::attack()
{
	std::cout << name_  << " attacks with" << weaponPtr_->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weaponPtr)
{
	weaponPtr_ = &weaponPtr;
}