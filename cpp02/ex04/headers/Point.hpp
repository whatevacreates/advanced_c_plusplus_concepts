
#ifndef POINT_HPP
# define POINT_HPP

# include <cmath>
# include <iostream>
# include <limits>
# include <random>
# include <string>
#include <sstream>

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

	float calcField(Point const a, Point const b, Point const c, int flag);
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);
float	randomFloat(int a, int b);
void	runTests(int min, int max, int numberTests);
int		randomInt(int a, int b);
void	validateNumbers(float a);

#endif