#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Utils.hpp"

Cure::Cure(): AMateria("cure")
{
    std::cout << PASTEL_SUN <<  "Cure: default constructor called." << RESET <<std::endl;
}

Cure::Cure(const Cure& other): AMateria(other)
{
 std::cout << PASTEL_SUN <<  "Cure: copy constructor called." << RESET <<std::endl;
}


Cure& Cure::operator=(const Cure& other)
{
    std::cout << PASTEL_SUN <<  "Cure: copy assignment operator called." << RESET <<std::endl;
    if(this != &other)
    {
        AMateria::operator=(other);
        //calls BASE CLASS assignment operator
    }
    return *this;
}

AMateria* Cure::clone() const
{
    std::cout << PASTEL_SUN <<  "Cure: calling clone, creating a deep copy." << RESET <<std::endl;
    return new Cure(*this);

}

void Cure::use(ICharacter& target)
{
    std::cout << PASTEL_SUN << B_CYAN << "Cure: *heals " << target.getName() << "'s wounds *" <<  RESET <<std::endl;
}

Cure::~Cure()
{
 std::cout << PASTEL_SUN <<  "Cure: destructor called." << RESET <<std::endl;
}
