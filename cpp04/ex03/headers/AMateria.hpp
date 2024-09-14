#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>

class AMateria
{
    protected:

    private:
    [...]
    public:
    AMateria(std::string const & type);
    [...]

    std::string const & getType() const; //return the  meateria type

    virtual AMateria* clone() const = 0;
    virtual void use(IChareacter& target);
};