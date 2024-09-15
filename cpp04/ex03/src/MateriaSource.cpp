#include "Utils.hpp"
#include "Character.hpp"

Character::Character():name(nullptr)
{
    std::cout <<PASTEL_MINT<<"Character: Default constructor called" << RESET << std::endl;
    return;
}

Character::Character(std::string name):this.name(name)
{
    std::cout <<PASTEL_MINT<<"Character: Parameterized constructor called" << RESET << std::endl;
     return;
}

Character::Character(const Character& other)
{
     std::cout <<PASTEL_MINT<<"Character: Default constructor called" << RESET << std::endl;
     return *this;
}

Character& Character::operator(const Character& other)
{
    if(this != &other)
    {
        name = other.name;
    }
    return *this;
}

void Character::equip(AMateria* m)
{
    for(int i = 0; i < 4; i++)
    {
        if(!inventory[i])
        {
            inventory[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx)
{
    if(idx >= 0 && idx < 4)
    inventory[idx] = nullptr;
}

void Character::use(int idx, ICharacter& target)
{
if(idx >= 0 && idx < 4 && inventory[idx])
inventory[idx]->use(target);
}