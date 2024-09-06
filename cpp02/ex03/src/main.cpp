#include "Fixed.hpp"
#include "Point.hpp"

int	main(void)
{
	Point const a(1, 3);
	Point const b(3, 4);
	Point const c(2, 1);
	Point const point(6, 3);
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
