#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
  public:
	Fixed(); //default constructor
	Fixed(const Fixed& copy); //copy constructor
	Fixed& operator=(const Fixed& copy); //copy assignment operator overload
	~Fixed(); //decontructor
	int getRawBits(void) const;
	void setRawBits(int const raw);

  private:
	int _fixedPoint;
    static const int _fractionalBits = 8;
};

#endif


/*
A default constructor that initializes the fixed-point number value to 0.
◦ A copy constructor.
◦ A copy assignment operator overload.
◦ A destructor.*/