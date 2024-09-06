
#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointNumValue(0)
{
	return ;
}

Fixed::Fixed(const Fixed &other) : _fixedPointNumValue(other.getRawBits())
{
	return ;
}

Fixed::Fixed(const int arg)
{
	_fixedPointNumValue = arg << _fractionalBits;
}

Fixed::Fixed(const float arg)
{
	_fixedPointNumValue = roundf(arg * (1 << _fractionalBits));
}

Fixed::~Fixed()
{
	return ;
}
Fixed &Fixed::operator=(const Fixed &other)
{
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

Fixed Fixed::operator+(const Fixed &other) const
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other) const
{
	return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed Fixed::operator*(const Fixed &other) const
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

bool Fixed::operator>(const Fixed &other) const
{
	return (this->_fixedPointNumValue > other._fixedPointNumValue);
}

bool Fixed::operator==(const Fixed &other) const
{
	return (this->_fixedPointNumValue == other._fixedPointNumValue);
}

bool Fixed::operator<(const Fixed &other) const
{
	return (this->_fixedPointNumValue < other._fixedPointNumValue);
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (this->_fixedPointNumValue != other._fixedPointNumValue);
}

Fixed &Fixed::max(Fixed &numA, Fixed &numB)
{
	return ((numA._fixedPointNumValue > numB._fixedPointNumValue) ? numA : numB);
}

const Fixed &Fixed::max(const Fixed &numA, const Fixed &numB)
{
	return ((numA._fixedPointNumValue > numB._fixedPointNumValue ? numA : numB));
}

Fixed &Fixed::min(Fixed &numA, Fixed &numB)
{
	return ((numA._fixedPointNumValue > numB._fixedPointNumValue) ? numB : numA);
}

const Fixed &Fixed::min(const Fixed &numA, const Fixed &numB)
{
	return ((numA._fixedPointNumValue > numB._fixedPointNumValue ? numB : numA));
}

Fixed &Fixed::operator++(void)
{
	this->_fixedPointNumValue++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	_fixedPointNumValue++;
	return(temp);
}

Fixed &Fixed::operator--(void)
{

	_fixedPointNumValue--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	_fixedPointNumValue--;
	return(temp);
}
