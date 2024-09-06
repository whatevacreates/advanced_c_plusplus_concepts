#ifndef FIXED_HPP
# define FIXED_HPP

# include <cmath>
# include <iostream>
# include <string>

class Fixed
{
  private:
	int _fixedPointNumValue;
	static const int _fractionalBits = 8;

  public:
	Fixed();

	//copy constructors:
	Fixed(const int arg);
	Fixed(const float arg);
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other);

	//arithmetic operators assignments:
	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;

	Fixed &operator++();   // pre
	Fixed &operator--();   // pre
	Fixed operator--(int); // post
	Fixed operator++(int); // post

	//comparison operators assignments:
	bool operator>(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;

	//destructor:
	~Fixed();

	//function members:
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;

	//static function members:
	static Fixed &min(Fixed &numA, Fixed &numB);
	static const Fixed &min(Fixed const &numA, Fixed const &numB);
	static Fixed &max(Fixed &numA, Fixed &numB);
	static const Fixed &max(Fixed const &numA, Fixed const &numB);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
