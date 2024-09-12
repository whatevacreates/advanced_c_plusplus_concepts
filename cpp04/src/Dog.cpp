#include "../headers/Dog.hpp"
#include "../headers/Animal.hpp"

Dog::Dog():Animal()
{
    Animal::setType("Dog");
    Animal::setSound("Barking grrrr.. <dog>");
    std::cout << "Dog default constructor called." << std::endl;
     return;
}

Dog::Dog(std::string type): Animal(type)
{
    Dog::setSound("How how how... <dog>");
std::cout << "Dog: parametrerized constructor called." << std::endl;
return;
}

Dog::~Dog()
{
    std::cout << "Dog destructor is called." << std::endl;
    return;
}