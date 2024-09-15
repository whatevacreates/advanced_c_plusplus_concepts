#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>

class ICharacter; // forward declaration to avoid circular dependecy; it's telling the compiler that the function exists
//without giving the full definition straight away, without thisb there might be an endless loop
class AMateria
{
    protected:
    std::string type;

    public:
    AMateria();
    AMateria(const AMateria& other);
    AMateria& operator=(const AMateria& other);
    AMateria(std::string const & type);
    virtual ~AMateria();
    std::string const & getType() const; //return the  materia type
    virtual AMateria* clone() const = 0;
    virtual void use(IChareacter& target);
};

#endif