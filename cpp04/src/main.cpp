#include "../headers/Animal.hpp"
#include "../headers/Cat.hpp"
#include "../headers/Dog.hpp"
#include "../headers/WrongCat.hpp"
#include "../headers/WrongAnimal.hpp"


int main(void)
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const WrongAnimal* wrongAnimal = new WrongAnimal();
    const WrongCat* wrongCat= new WrongCat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    
    i->makeSound(); //cat sound
    j->makeSound();
    wrongAnimal->makeSound();
    wrongCat->makeSound();
    meta->makeSound();

    delete(i);
    delete(j);
    delete(meta);
    delete(wrongAnimal);
    delete(wrongCat);

}