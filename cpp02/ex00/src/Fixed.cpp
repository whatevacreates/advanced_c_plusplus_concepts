#include "Fixed.hpp"

Fixed::Fixed() : _fixedPoint(0)
{
	return ;
}

Fixed::Fixed(const Fixed &copy) : _fixedPoint(copy._fixedPoint)
{
	return ;
}

Fixed& Fixed::operator=(const Fixed& copy) ///assignemnt operator overload
{
	if (this != &copy)
	{
		this->_fixedPoint = copy._fixedPoint = copy.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed()
{
	return ;
}

const int Fixed::getRawBits()
{
	return (_fixedPoint);
}

void Fixed::setRawBits(int const raw)
{
    raw = _fixedPoint;
}