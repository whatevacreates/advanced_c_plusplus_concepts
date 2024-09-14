#ifndef BRAIN_CPP
# define BRAIN_CPP

# include <iostream>
# include <string>

class Brain
{
  private:
	std::string _ideas[100];

  public:
	Brain();
	Brain(std::string idea);
	Brain(const Brain &others);
	Brain &operator=(const Brain &others);
	virtual ~Brain();
	void printIdeas() const;
};

#endif
