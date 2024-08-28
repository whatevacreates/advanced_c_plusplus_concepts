#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <cctype>
# include <iostream>
# include <string>

class Zombie
{
  public:
	Zombie();
	~Zombie();
	void announce(void);
	void setName(std::string name);

  private:
	std::string name;
};

Zombie	*zombieHorde(int N, std::string name);

#endif