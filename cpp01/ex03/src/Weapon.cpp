#include "HumanA.h"
#include "HumanB.h"
#include "Weapon.h"

Weapon::Weapon()
{
	return ;
}
Weapon::Weapon(const std::string &type) : type_(type)
{
	return ;
}

Weapon::~Weapon()
{
	return ;
}

const std::string &Weapon::getType()
{
	return (type_);
}

void Weapon::setType(const std::string &newType)
{
	type_ = newType;
}