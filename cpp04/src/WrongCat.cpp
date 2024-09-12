#include "../headers/WrongCat.hpp"
#include "../headers/WrongAnimal.hpp"

WrongCat::WrongCat():WrongAnimal()
{
    _type = "WrongCat";
    std::cout << "Wrong default constructor called." << std::endl;
     return;
}

WrongCat::WrongCat(std::string type): WrongAnimal(type)
{
   
std::cout << "WrongCat: parametrerized constructor called." << std::endl;
return;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor is called." << std::endl;
    return;
}

void WrongCat::makeSound(void)const{
std::cout << "Meow sssssss..." <<std::endl;
}

