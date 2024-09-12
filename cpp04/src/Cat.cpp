#include "../headers/Cat.hpp"
#include "../headers/Animal.hpp"

Cat::Cat():Animal()
{
    Animal::setType("Cat");
    Animal::setSound("Miau miau... <cat>");
    std::cout << "Cat default constructor called." << std::endl;
     return;
}

Cat::Cat(std::string type): Animal(type)
{
    Cat::setSound("Miau miau kici kici... <cat>");
std::cout << "Cat: parametrerized constructor called." << std::endl;
return;
}

Cat::~Cat()
{
    std::cout << "Cat destructor is called." << std::endl;
    return;
}