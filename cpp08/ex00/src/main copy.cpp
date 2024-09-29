#include "EasyFind.hpp"
#include "Utils.hpp"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int	main(void)
{
	int	array[] = {1, 2, 3, 4, 5};
	int	length;

	length = sizeof(array) / sizeof(array[0]);
	std::vector<int> vectorInt;
	vectorInt.assign(array, array + length);
	std::cout << B_ROSE << BOLD << ":::::::::::::::::::::::::::::::::::::::: TEST 1: element not found ::::::::::::::::::::::::::::::::::::::::" << RESET << std::endl;
	try
	{
		easyfind(vectorInt, 30);
		std::cout << "success" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << B_ROSE << BOLD << ":::::::::::::::::::::::::::::::::::::::: TEST 2: element is found ::::::::::::::::::::::::::::::::::::::::" << RESET << std::endl;
	try
	{
		easyfind(vectorInt, 2);
		throw std::runtime_error("The first argument is not the container of intergers");
		std::cout << ITALIC << B_BABY_BLUE << "Element is found." << RESET << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << B_ROSE << BOLD << ":::::::::::::::::::::::::::::::::::::::: TEST 3: another container type ::::::::::::::::::::::::::::::::::::::::" << RESET << std::endl;
	try
	{
		easyfind(array, 4);
		std::cout << "Yeah the element is found in the container of ints." << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;
    std::cout << B_ROSE << BOLD << ":::::::::::::::::::::::::::::::::::::::: TEST 3: another container type ::::::::::::::::::::::::::::::::::::::::" << RESET << std::endl;
	try
	{
        std::string arrayString = "summer";
        //std::string arrayString[10] = {"anna", "beata", "basia", "teresa", "linda"};
		easyfind(arrayString, 4);
        throw std::runtime_error("wrong parameter");
		std::cout << "Yeah the element is found in the container of ints." << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}
