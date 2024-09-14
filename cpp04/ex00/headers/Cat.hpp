
#ifndef CAT_CPP
# define CAT_CPP

# include "Animal.hpp"
# include <iostream>
# include <string>

class Cat : public Animal
{
  public:
	Cat();
	Cat(std::string type);
	Cat(const Cat &other);
	Cat &operator=(const Cat &other);
	~Cat();
	void makeSound() const;
};
#endif
