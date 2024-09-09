#include "Fixed.hpp"
#include "Point.hpp"

void	checkDigits(std::string str)
{
	size_t	i;

	i = 0;
	if (str[0] == '0' && str.length() > 1)
	{
		std::cout << "Your input cannot start from 0 and cannot be 0." << std::endl;
		exit(1);
	}
	if (str[0] == '-' && str.length() > 1)
	{
		std::cout << "Your input cannot be a negative number." << std::endl;
		exit(1);
	}
	while (i < str.length())
	{
		if (!isdigit(str[i]))
		{
			std::cout << "Your input needs to consists of digits only."
							"Input ints only."
						<< std::endl;
			exit(1);
		}
		i++;
	}
}
int	main(void)
{
	int	min;
	int	max;
	int tests;

	std::string min_str;
	std::string max_str;
	std::string tests_str;
	std::cout << "Output int range for your tests: " << std::endl;
	std::cout << "Min value: " << std::endl;
	std::getline(std::cin, min_str);
	std::cout << "Max value: " << std::endl;
	std::getline(std::cin, max_str);
	std::cout << "Number of tests to run: " << std::endl;
	std::getline(std::cin, tests_str);
	checkDigits(max_str);
	checkDigits(min_str);
	try
	{
		min = std::stoi(min_str);
		max = std::stoi(max_str);
		tests = std::stoi(tests_str);
	}
	catch (const std::invalid_argument &e)
	{
		std::cout << "Invalid argument: not a valid integer." << std::endl;
		return (1);
	}
	catch (const std::out_of_range &e)
	{
		std::cout << "Out of range: value is too large or too small for an int." << std::endl;
		return (1);
	}
	runTests(min, max, tests);
	return (0);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Point		main;
	float		mainT;
	float		trianA;
	float		trianB;
	float		trianC;
	const float	epsilon = 0.01f;

	mainT = main.calcField(a, b, c, 1);
	trianA = main.calcField(a, b, point, 0);
	trianB = main.calcField(a, point, c, 0);
	trianC = main.calcField(point, b, c, 0);
	/*
	check the fields:
	std::cout << "mainTriangle :" << mainT << std::endl;
	std::cout << "A: " << trianA << std::endl;
	std::cout << "B: " << trianB << std::endl;
	std::cout << "C: " << trianC << std::endl;*/
	if (std::fabs(trianA) < epsilon || std::fabs(trianB) < epsilon
		|| std::fabs(trianC) < epsilon)
	{
		std::cout << "\nThe point is on the border of the triangle.";
		return (false);
	}
	return (std::fabs(mainT - (trianA + trianB + trianC)) < epsilon);
}

