#include <iostream>
#include <string>

#ifndef WEAPON_H
# define WEAPON_H

class Weapon
{
  public:
	Weapon();
	Weapon(const std::string &type);
	~Weapon();
	const std::string &getType();
	void setType(const std::string &newType);

  private:
	std::string type_;
};

#endif
