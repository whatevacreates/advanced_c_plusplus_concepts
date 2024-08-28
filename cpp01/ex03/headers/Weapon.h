#include <iostream>
#include <string>

class Weapon
{
    public:
    Weapon(const std::string& type_);
    ~Weapon();
    const std::string& getType() const;
    void setType(const std::string& newType);

    private:
    std::string type_;
};


#endif





/*
#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
public:
    // Constructor that takes a type
    Weapon(const std::string& type);
    ~Weapon();

    // Getter for weapon type
    const std::string& getType() const;

    // Setter for weapon type
    void setType(const std::string& newType);

private:
    std::string type_;  // private attribute for weapon type
};

#endif












class Weapon
{
	private:
		std::string	_type;

	public:
		Weapon();
		Weapon(const std::string& initType);
		~Weapon();
		const std::string&	getType(void);
		void	setType(const std::string& newType);
};

#endif*/