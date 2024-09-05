
#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointNumValue(0)
{
	std::cout << "Default constructor called." << std::endl;
	return ;
}

Fixed::Fixed(const Fixed &other) : _fixedPointNumValue(other.getRawBits())
{
	std::cout << "Copy constructor called." << std::endl;
	return ;
}

Fixed::Fixed(const int arg)
{
	std::cout << "Constructor accepting const int called." << std::endl;
	_fixedPointNumValue = arg << _fractionalBits;
}

Fixed::Fixed(const float arg)
{
	std::cout << "Constructor accepting const float called." << std::endl;
	_fixedPointNumValue = roundf(arg * (1 << _fractionalBits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called." << std::endl;
	return ;
}
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called." << std::endl;
	if (this != &other)
	{
		this->_fixedPointNumValue = other.getRawBits();
	}
	return (*this);
}

int Fixed::getRawBits(void) const
{
	return (_fixedPointNumValue);
}

void Fixed::setRawBits(int const raw)
{
	_fixedPointNumValue = raw;
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(_fixedPointNumValue) / (1 << _fractionalBits));
		// Proper conversion to float
}

int Fixed::toInt(void) const
{
	return (_fixedPointNumValue / (1 << _fractionalBits));
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

/*
Default constructor called.
Constructor accepting const int called.
Constructor accepting const float called.
Copy constructor called.
Constructor accepting const float called.
Deconstructor called.
a is 1234.43
b is 10
c is 42.418
d is 10
a is 1234 as integer
b is 10 as integer
c is 42 as integer
d is 10 as integer
Deconstructor called.
Deconstructor called.
Deconstructor called.
Deconstructor called.
*/