#include "Weapon.h"

#ifndef HUMANB_H
# define HUMANB_H

class HumanB
{
  public:
	HumanB(std::string name_);
	~HumanB();
	void attack();
    void setWeapon(Weapon &weaponPtr);

  private:
	std::string name_;
	Weapon *weaponPtr_;
};

#endif