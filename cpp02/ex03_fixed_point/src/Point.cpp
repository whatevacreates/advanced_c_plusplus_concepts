#include "Fixed.hpp"
#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
	return ;
}

Point::Point(const float x, const float y)
{
	_x = x;
	_y = y;
	std::cout << "check" << _x << _y << std::endl;
	return ;
}

Point::Point(const Point &other) : _x(other._x), _y(other._y)
{
	return ;
}

Point &Point::operator=(const Point &other)
{
	if (this != &other)
	{
		_x = other._x;
		_y = other._y;
	}
	return (*this);
}

Point::~Point()
{
	return ;
}

/*
float	Point::calcField(Point const a, Point const b, Point const c)
{
	float	sum;
	float	sum;

	std::cout << " a._x " << a._x * b._y << std::endl;
		std::cout << " a._y" << a._y << std::endl;
		std::cout << " b._x " << b._x << std::endl;
		std::cout << " b._y " << b._y << std::endl;
		sum = ((a._x * b._y + b._x * c._y + c._x * a._y) - (a._y * b._x + b._y
					* c._x + c._y * a._x)) / 2;
		std::cout << " sum " << sum << std::endl;
		return (std::fabs(sum));
}*/
float Point::calcField(Point const a, Point const b, Point const c)
{
    int sum;
    float ret;
	Fixed a_x(a._x);
	Fixed b_y(b._y);
	Fixed b_x(b._x);
	Fixed c_y(c._y);
	Fixed c_x(c._x);
	Fixed a_y(a._y);

	sum = ((a_x * b_y + b_x * c_y + c_x * a_y) - (a_y * b_x + b_y
				* c_x + c_y * a_x)) / 2;
ret = sum.toFloat();
	std::cout << " ret " << ret << std::endl;
	return (std::fabs(ret));
}
