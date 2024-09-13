#include "../headers/Animal.hpp"
#include "../headers/Cat.hpp"
#include "../headers/Dog.hpp"
#include "../headers/WrongCat.hpp"
#include "../headers/WrongAnimal.hpp"
#include "../headers/Utils.hpp"


int main(void)
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
   

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    
    i->makeSound(); //cat sound
    j->makeSound();
    
    meta->makeSound();

    delete(i);
    delete(j);
    delete(meta); 
    std::cout << ULINE << PASTEL_CORAL << "\nWRONG ANIMALS:\n"<< RESET << std::endl;
    const WrongAnimal* wrongAnimal = new WrongAnimal();
    const WrongCat* wrongCat = new WrongCat();
    std::cout << wrongAnimal->getType() << ": is this a wrong animal? " << std::endl;
    std::cout << wrongCat->getType() << ": is this a wrong cat? " << std::endl;
    wrongAnimal->makeSound();
    wrongCat->makeSound();
    delete(wrongAnimal);
    delete(wrongCat);
}
