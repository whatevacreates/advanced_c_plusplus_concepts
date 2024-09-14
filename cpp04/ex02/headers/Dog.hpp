#ifndef DOG_CPP
# define DOG_CPP

# include "A_Animal.hpp"
# include "Brain.hpp"
# include <ostream>
# include <string>

class Dog : public Animal
{
  private:
	std::string _dogIdea;
	Brain *_dogBrain;

  public:
	Dog();
	Dog(std::string idea);
	Dog(const Dog &other);
	Dog &operator=(const Dog &other);
	virtual ~Dog();
	void makeSound() const;
	virtual void printIdeas() const;
};
#endif
