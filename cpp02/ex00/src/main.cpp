#include "Fixed.hpp"

int	main(void)
{
	Fixed a;
	Fixed b(a); ///making a copy using copy contructor
	Fixed c;
	c = b; //making a copy by using assignemnt operator
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return (0);
}