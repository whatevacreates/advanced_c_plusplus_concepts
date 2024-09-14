
#ifndef CAT_CPP
# define CAT_CPP

# include "A_Animal.hpp"
# include "Brain.hpp"
# include <iostream>
# include <string>

class Cat : public Animal
{
  private:
	std::string _catIdea;
	Brain *_catBrain;

  public:
	Cat();
	Cat(std::string type);
	Cat(const Cat &other);
	Cat &operator=(const Cat &other);
	~Cat();
	void makeSound() const;
	virtual void printIdeas() const;
};
#endif
