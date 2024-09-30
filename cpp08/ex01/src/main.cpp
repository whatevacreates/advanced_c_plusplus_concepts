#include "Span.hpp"
#include "Utils.hpp"
#include <vector>

int	main(void)
{
	Span sp = Span(5);
	Span test = Span(6);
	std::vector<int> arrayInt;
	arrayInt.push_back(6);
	arrayInt.push_back(8);
	arrayInt.push_back(9);
	arrayInt.push_back(1);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << std::endl;
	std::cout << BOLD << B_DUSTY_ROSE << ":::::::::::::::::::: TEST 1 ::::::::::::::::::::" << RESET << std::endl;
	try
	{
		sp.addNumber(80);
	}
	catch (std::runtime_error &e)
	{
		std::cout << "Runtime error: " << e.what() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << BOLD << B_DUSTY_ROSE << ":::::::::::::::::::: TEST 2 ::::::::::::::::::::" << RESET << std::endl;
	try
	{
		test.addNumber(7);
		std::cout << test.shortestSpan() << std::endl;
	}
	catch (std::runtime_error &e)
	{
		std::cout << "Runtime error: " << e.what() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << BOLD << B_DUSTY_ROSE << ":::::::::::::::::::: TEST 3 ::::::::::::::::::::" << RESET << std::endl;
	try
	{
		test.addRange(arrayInt.begin(), arrayInt.end());
		std::cout << "Shortest span: " << test.shortestSpan() << std::endl;
		std::cout << "Longest span: " << test.longestSpan() << std::endl;
	}
	catch (const std::runtime_error &e)
	{
		std::cout << "Runtime error: " << e.what() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	return (0);
}