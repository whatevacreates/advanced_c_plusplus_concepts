#ifndef DOG_CPP
# define DOG_CPP

# include "Animal.hpp"
# include <ostream>
# include <string>

class Dog : public Animal
{
  public:
	Dog();
	Dog(std::string type);
	Dog(const Dog &other);
	Dog &operator=(const Dog &other);
	virtual ~Dog();
	void makeSound() const;
};
#endif
