
#ifndef POINT_HPP
# define POINT_HPP

# include <cmath>
# include <iostream>

class Point
{
  private:
	float _x;
	float _y;

  public:
	Point();
	Point(const float x, const float y);
	Point(const Point &other);
	Point &operator=(const Point &other);
	~Point();
    float calcField(Point const a, Point const b, Point const c);
    
};

bool bsp( Point const a, Point const b, Point const c, Point const point);
#endif