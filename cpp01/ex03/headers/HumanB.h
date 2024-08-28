#include "Weapon.h"

#ifndef HUMANB_H
#define HUMANB_H

class HumanB
{
    public:
    HumanB(std::string name_);
    ~HumanB();
    void attack(const Weapon* weaponPtr_);

    private:
    std::string name_;
    Weapon* weaponPtr_;

}

#endif