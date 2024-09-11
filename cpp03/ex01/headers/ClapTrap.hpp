#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
#include <string>

class ClapTrap
{
    private:
    std::string _name;
    int _hits;
    int _energy;
    int _damage;

    protected:
    // setters:
    void setHits(int hits);
    void setEnergy(int energy);
    void setDamage(int damage);
    void setName(std::string name);

    public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap &other);
    ClapTrap& operator=(const ClapTrap &other);
    ~ClapTrap();

    void attack(const std::string& target);
    void attacks_loop(int attacks, ClapTrap *attacker, ClapTrap *target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    int checkEnergyLevel();

    //getters:
    int getHits();
    int getEnergy();
    int getDamage();
    std::string getName();
};

#endif