#include "../headers/WrongCat.hpp"
#include "../headers/WrongAnimal.hpp"

WrongCat::WrongCat():WrongAnimal()
{
    WrongAnimal::setType("WrongCat");
    WrongAnimal::setSound("Miau miau... <wrong cat>");
    std::cout << "Wrong default constructor called." << std::endl;
     return;
}

WrongCat::WrongCat(std::string type): WrongAnimal(type)
{
    WrongCat::setSound("Miau miau kici kici... <cat>");
std::cout << "WrongCat: parametrerized constructor called." << std::endl;
return;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor is called." << std::endl;
    return;
}