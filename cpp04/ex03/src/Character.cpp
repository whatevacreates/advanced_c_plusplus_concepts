#include "Utils.hpp"
#include "Character.hpp"

Character::Character():name(nullptr)
{
     for(int i = 0; i < 4; i++)
    {
        inventory[i] = 0;
    }
    std::cout << PASTEL_ROSE << "Character: default constructor called." << RESET << std::endl;
    return;
}

Character::Character(std::string name)
{
    this->name = name;
    for(int i = 0; i < 4; i++)
    {
        inventory[i] = 0;
    }
    std::cout << PASTEL_ROSE << name << " is born!" << " | Character: parameterized constructor called." << RESET << std::endl;
    return;
}

Character::Character(const Character& other)
{
    std::cout << PASTEL_ROSE << "Character: copy constructor called." << RESET << std::endl;
    for(int i = 0; i < 4; i++)
    {
        if(other.inventory[i])
        inventory[i] = other.inventory[i];
        else 
        inventory[i] = 0;
    }
}

Character& Character::operator=(const Character& other)
{
    std::cout << PASTEL_ROSE << "Character: copy constructor called." << RESET << std::endl;
    if(this != &other)
    {
        
        for(int i = 0; i < 4; i++)
        {
            if(other.inventory[i])
            this->inventory[i] = other.inventory[i];
            else
            this->inventory[i] = 0;
        }
    }
    
    return *this;
}

Character::~Character()
{
    return;
}

void Character::equip(AMateria* m)
{
    for(int i = 0; i < 4; i++)
    {
        if(!inventory[i])
        inventory[i] = m;
        std::cout << PASTEL_ROSE << name << "Equip " << " by " << m->getType() << RESET << std::endl;
        break;
    }
}

void Character::unequip(int idx)
{
    if(inventory[idx] && idx >= 0 && idx < 4 )
    {
        std::cout << PASTEL_ROSE << name << "Unequipped slot: " << idx << RESET << std::endl;
        inventory[idx] = 0;
    }
    
}


void Character::use(int idx, ICharacter& target)
{
    if(idx >= 0 && idx < 4 && inventory[idx])
    {
         std::cout << PASTEL_ROSE << name << "Using " << inventory[idx] << RESET << std::endl;
         inventory[idx]->use(target);
    }
   
}

std::string const & Character::getName() const
{
    return name;
}