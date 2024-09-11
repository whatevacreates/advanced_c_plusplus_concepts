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

float Point::calcField(Point const a, Point const b, Point const c, int flag)
{
	Fixed calc;
	validateNumbers(a._x);
	validateNumbers(b._x);
	validateNumbers(c._x);
	validateNumbers(a._y);
	validateNumbers(b._y);
	validateNumbers(c._y);
	if ((flag == 1) && ((a._x == b._x && a._y == b._y) || (b._x == c._x
				&& b._y == c._y) || (a._x == c._x && a._y == c._y)))
	{
		std::cout << "This is not a triangle, check your input." << std::endl;
		return (0);
	}
	Fixed a_x(a._x), b_y(b._y), b_x(b._x), c_y(c._y), c_x(c._x), a_y(a._y);
	return (calc.return_sum(a_x, b_y, b_x, c_y, c_x, a_y));
}

