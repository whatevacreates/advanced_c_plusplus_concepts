#include "../headers/WrongAnimal.hpp"
#include "../headers/WrongCat.hpp"
#include "../headers/Utils.hpp"

#include "WrongCat.hpp"

WrongCat::WrongCat() {
    _type = "😼 WrongCat";
    std::cout << PASTEL_TURQUOISE << ITALIC << "😼 WrongCat: constructor called" << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat& other)
{
    *this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    if(this != &other)
    {
        _type = other._type;
    }
    return *this;
}

WrongCat::~WrongCat() {
   std::cout << PASTEL_TURQUOISE << ITALIC << "😼 WrongCat destructor called" << RESET << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << PASTEL_TURQUOISE << ITALIC << "😼 WrongCat: Miau miau miau miau..." << RESET << std::endl;
}