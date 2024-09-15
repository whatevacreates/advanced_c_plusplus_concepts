#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Utils.hpp"


Ice::Ice(): AMateria("ice")
{
    std::cout << PASTEL_TURQUOISE<<  "Ice: default constructor called." << RESET <<std::endl;
}

Ice::Ice(const Ice& other): AMateria(other)
{
 std::cout << PASTEL_TURQUOISE <<  "Ice: copy constructor called." << RESET <<std::endl;
}


Ice& Ice::operator=(const Ice& other)
{
    std::cout << PASTEL_TURQUOISE <<  "Ice: copy assignment operator called." << RESET <<std::endl;
    if(this != &other)
    {
        AMateria::operator=(other);
        //calls BASE CLASS assignment operator
    }
    return *this; 
}

AMateria* Ice::clone() const
{
    std::cout << PASTEL_TURQUOISE <<  "Ice: calling clone, creating a deep copy." << RESET <<std::endl;
    return new Ice(*this);

}

void Ice::use(ICharacter& target)
{
    std::cout << PASTEL_TURQUOISE <<  "Ice: *shoots an ice bolt at " << target.getName() << " *" <<  RESET <<std::endl;
}