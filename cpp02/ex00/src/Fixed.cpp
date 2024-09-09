
#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointNumValue(0)
{
	std::cout << "Default constructor called." << std::endl;
	return ;
}

Fixed::Fixed(const Fixed &other) : _fixedPointNumValue(other._fixedPointNumValue)
{
	std::cout << "Copy constructor called." << std::endl;
	return ;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called." << std::endl;
	if (this != &other)
	{
		_fixedPointNumValue = other.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Deconstructor called." << std::endl;
	return ;
}

int Fixed::getRawBits(void) const

{
	std::cout << "getRawBits member function called." << std::endl;
	return (_fixedPointNumValue);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called." << std::endl;
	_fixedPointNumValue = raw;
}

int Fixed::return_sum()
{
	int sum;
	return sum;
}
