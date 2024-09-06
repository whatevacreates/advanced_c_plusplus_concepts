#include "Fixed.hpp"
#include "Point.hpp"

int	main(void)
{
	Point const a(1.11, 3.34232);
	Point const b(3.42342, 4.322);
	Point const c(2.322, 1.32);
	Point const point(1.22, 3);
	if (bsp(a, b, c, point))
		std::cout << "Yes, the point is within the triangle!" << std::endl;
	else
		std::cout << "No,"
						"the point is outside the triangle on on the triangle's border"
					<< std::endl;
	return (0);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Point	main;
	float	mainT;
	float	trianA;
	float	trianB;
	float	trianC;

	mainT = main.calcField(a, b, c);
	trianA = main.calcField(a, b, point);
	trianB = main.calcField(a, point, c);
	trianC = main.calcField(point, b, c);
	std::cout << "mainT" << mainT << std::endl;
    std::cout << "A" << trianA << std::endl;
     std::cout << "B" << trianB << std::endl;
      std::cout << "C" << trianB << std::endl;
	return (mainT == (trianA + trianB + trianC));
}

/*
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);
	a = Fixed(1234.4321f);
*/
