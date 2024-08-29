#include "Weapon.h"

#ifndef HUMANA_H
# define HUMANA_H

class HumanA
{
  public:
	HumanA(std::string name, Weapon &weaponRef);
	~HumanA();
	void attack();

  private:
	std::string name_;
	Weapon &weaponRef_;
};

#endif