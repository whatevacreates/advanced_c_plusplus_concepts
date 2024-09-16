#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Utils.hpp"

AMateria::AMateria():type("")
{
    std::cout <<PASTEL_LIME<<"AMateria: Default constructor called" << RESET << std::endl;
    return;
}

AMateria::AMateria(std::string const &type)
{
    std::cout <<PASTEL_LIME<<"AMateria: Parameterized constructor called" << RESET << std::endl;
    this->type = type;
}

AMateria::AMateria(const AMateria& other)
{
     std::cout <<PASTEL_LIME<<"AMateria: Copy constructor called" << RESET << std::endl;
     if(this != &other)
     this->type = other.type;
}

AMateria& AMateria::operator=(const AMateria& other)
{
    std::cout << PASTEL_LIME<<"AMateria: Copy assignment operator called" << RESET << std::endl;
    if(this != &other)
    {
      this->type = other.type;

    }
    return *this;
}

std::string const & AMateria::getType() const
{
    return type;
}

AMateria::~AMateria()
{
    std::cout <<PASTEL_LIME<<"AMateria: Destructor called" << RESET << std::endl;
    return;
}

void AMateria::use(ICharacter &target)
{
    std::cout << "THIS SHOULD NOT BE CALLED-------------------------------" << std::endl;
    std::cout << PASTEL_LIME <<  this->type << " used on " << target.getName() <<  RESET <<std::endl;
}