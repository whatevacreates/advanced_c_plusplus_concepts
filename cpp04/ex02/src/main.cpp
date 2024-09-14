#include "../headers/A_Animal.hpp"
#include "../headers/Cat.hpp"
#include "../headers/Dog.hpp"
#include "../headers/WrongCat.hpp"
#include "../headers/WrongAnimal.hpp"
#include "../headers/Utils.hpp"


int		main(void)
{
    Animal *array_animals[10];

    /* uncommenting this will cause a compilation error, because Animal class is an abstract class.
    Animal animal;
    */
std::cout << "To test an abstract class, uncomment the code: Animal animal in main.cpp" << std::endl;
std::cout << BOLD << B_GREEN << "::::::::CREATING THE ARRAY OF ANIMAL OBJECTS::::::::" << RESET << std::endl;
for(int i = 0; i < 2; i++)
{
array_animals[i] = new Cat();

}
for(int i = 1; i < 2; i ++)
{
    array_animals[i] = new Dog();
}

std::cout << BOLD << B_MAGENTA << "::::::::TEST: PRINT IDEAS::::::::" << RESET << std::endl;
for(int i = 0; i <2; i++)
{
    array_animals[i]->printIdeas();
}

std::cout << BOLD << B_BLACK  << "::::::::DELETING THE ARRAY OF ANIMAL OBJECTS::::::::" << RESET << std::endl;

	for(int i = 0; i < 2; i++)
    {
        delete(array_animals[i]);
    }
}






