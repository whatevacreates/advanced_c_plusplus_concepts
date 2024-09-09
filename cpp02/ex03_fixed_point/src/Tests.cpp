#include "Fixed.hpp"
#include "Point.hpp"

void	runTests(int min, int max, int numberTests)
{
	for (int i = 1; i <= numberTests; i++)
	{
		std::cout << "\n"
					<< "test nr: " << i << std::endl;
		std::cout << "Triangle Points: ";
		Point const a(randomFloat(min, max), randomFloat(min, max));
		Point const b(randomFloat(min, max), randomFloat(min, max));
		Point const c(randomFloat(min, max), randomFloat(min, max));
		std::cout << "Point to check: ";
		Point const point(randomFloat(min, max), randomFloat(min, max));
		if (bsp(a, b, c, point))
		{
		  std::cout << "\n:::::::::::::::::'::::::::::::::::::::::" << std::endl;
			std::cout << "::::::::::::::::   :::::::::::::::::::::" << std::endl;
			std::cout << ":::::::::::::::     ::::::::::::::::::::" << std::endl;
			std::cout << "::::::::::::::       :::::::::::::::::::" << std::endl;
			std::cout << "YES, the point is within the triangle!!!" << std::endl;
			std::cout << "::::::::::::::       :::::::::::::::::::" << std::endl;
			std::cout << ":::::::::::::::     ::::::::::::::::::::" << std::endl;
			std::cout << "::::::::::::::::   :::::::::::::::::::::" << std::endl;
			std::cout << ":::::::::::::::::.::::::::::::::::::::::" << std::endl;
		}
		else
			std::cout << "\n--- NO, "
							"the point is outside the triangle."
						<< std::endl;
	}
}

float	randomFloat(int a, int b)
{
	float	ret;
	int		first;
	int		second;

	if (a > b || a == b || a <= 0 || b <= 0)
	{
		std::cout << "Min & max values need to be ints bigger than zero. "
						"Min needs to be smaller than max. Exiting now."
					<< std::endl;
		exit(1);
	}
	first = randomInt(a, b);
	second = randomInt(a, b);
	ret = (float)first / (float)second;
	ret = std::round(ret * 100) / 100;
	std::cout << ret << "; ";
	return (ret);
}

int	randomInt(int a, int b)
{
	std::random_device rd; // Obtain a random seed from hardware,
	// you need to "seed" the generator!
	std::default_random_engine generator(rd());
	std::uniform_int_distribution<int> distribution(a, b);
	return (distribution(generator));
}

void	validateNumbers(float a)
{
	if (std::isinf(a) || a < std::numeric_limits<float>::lowest()
		|| a > std::numeric_limits<float>::max())
	{
		std::cout << "\nInvalid values for the points, "
						"program cannot proceed."
					<< std::endl;
		exit(1);
	}
}