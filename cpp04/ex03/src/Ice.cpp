#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include <string>

class Ice
{
    private:
    std::string _type;
    public:
    Ice();
    Ice(const Ice& other);
    Ice& operator=(const Ice& other);
    ~Ice();
    Ice& clone(const &Ice other);
    void use(ICharacter&);
}