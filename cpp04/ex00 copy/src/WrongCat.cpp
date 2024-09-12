#include "../headers/WrongAnimal.hpp"
#include "../headers/WrongCat.hpp"


WrongCat::WrongCat() {
    type = "WrongCat";
    std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "WrongCat makes a different sound" << std::endl;
}
