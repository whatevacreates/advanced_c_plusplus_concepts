#include "Point.hpp"
#include "Fixed.hpp"

Point::Point():_x(0), _y(0)
{
    return;
}

Point::Point(const float x, const float y)
{
    _x = x;
    _y = y;
    std::cout << "check" << _x << _y <<std::endl;
    return;
}

Point::Point(const Point &other):_x(other._x), _y(other._y)
{
    return;
}

Point& Point::operator=(const Point &other)
{
    if(this != &other)
    {
        _x = other._x;
        _y = other._y;
    }
    

    return (*this);
}

Point::~Point()
{
    return;
}


float	Point::calcField(Point const a, Point const b, Point const c)
{
    float sum;
    std::cout << " a._x " << a._x * b._y << std::endl;
     std::cout << " a._y" << a._y << std::endl;
       std::cout << " b._x " << b._x << std::endl;
     std::cout << " b._y " << b._y << std::endl;
     sum = ((a._x * b._y + b._x * c._y + c._x * a._y) - (a._y * b._x + b._y * c._x + c._y * a._x)) / 2;
      std::cout << " sum " << sum << std::endl;
	 return std::fabs(sum);

}

