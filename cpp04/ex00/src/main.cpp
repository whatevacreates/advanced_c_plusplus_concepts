#include "../headers/Animal.hpp"
#include "../headers/Cat.hpp"
#include "../headers/Dog.hpp"
#include "../headers/Utils.hpp"
#include "../headers/WrongAnimal.hpp"
#include "../headers/WrongCat.hpp"

void	wrong_test(void)
{
	const WrongAnimal	*meta = new WrongAnimal();
	const WrongAnimal	*i = new WrongCat();
	delete				meta;
	delete				i;

	std::cout << i->getType() << " " << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	i->makeSound(); // will output the cat sound!
	meta->makeSound();
}

void	correct_test(void)
{
	const Animal	*meta = new Animal();
	const Animal	*j = new Dog();
	const Animal	*i = new Cat();
	delete			meta;
	delete			i;
	delete			j;

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	i->makeSound(); // will output the cat sound!
	j->makeSound(); // will output the dog sound!
	meta->makeSound();
}

int	main(void)
{
	correct_test();
	std::cout << "\n" << std::endl;
	std::cout << B_YELLOW << "             WRONG TEST             " << RESET << std::endl;
	wrong_test();
	return (0);
}

/*
int	main(void)
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
}*/
