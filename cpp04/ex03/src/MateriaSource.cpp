#include "Utils.hpp"
#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for(int i = 0; i < 4; i++)
    {
        templates[i] = nullptr;
    }
    std::cout <<PASTEL_SALMON << "MateriaSource: default constructor called." << RESET << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    for (int i = 0; i < 4; i++)
    {
        if(other.templates[i])
        templates[i]= other.templates[i]->clone();
        else
        templates[i] = nullptr;
    }
     std::cout <<PASTEL_SALMON << "MateriaSource: copy constructor called." << RESET << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    if(this != &other)
    {
        for(int i = 0; i < 4; i++)
        {
            if(other.templates[i])
            templates[i] = other.templates[i]->clone();
            else
            templates[i] = nullptr;
        }
    }
    std::cout <<PASTEL_SALMON << "MateriaSource: copy assignment operator called." << RESET << std::endl;
    return *this;
}

MateriaSource::~MateriaSource()
{
    for(int i = 0; i < 4; i++)
    {
        if(templates[i])
        delete templates[i];
    }
     std::cout <<PASTEL_SALMON << "MateriaSource: destructor called." << RESET << std::endl;
}

void MateriaSource::learnMateria(AMateria* m)
{
    for(int i = 0; i < 4; i++)
    {
        if(!templates[i])
        {
            templates[i] = m;
            std::cout <<PASTEL_SALMON <<  "Materia learned " << m->getType() << RESET <<  std::endl;
            break;
        }
    }
   std::cout <<PASTEL_SALMON << "MateriaSource: copy assignment operator called." << RESET << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
    for(int i = 0; i < 4; i++)
    {
        if(templates[i] && templates[i]->getType() == type)
        {
            std::cout  <<PASTEL_SALMON << "Creating Materia of type: " << type << RESET <<std::endl;
            return templates[i]->clone();
        }
    }
    std::cout  <<PASTEL_SALMON << "Unknown Materia type: " << type <<RESET << std::endl;
    return nullptr;
}