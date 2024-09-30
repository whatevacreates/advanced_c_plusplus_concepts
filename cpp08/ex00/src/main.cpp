#include "EasyFind.hpp"
#include "Utils.hpp"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void	testInt(int num)
{
	std::cout << "INT: \n" << num << std::endl;
	throw std::invalid_argument("Element not found.");
}

void	testString(DataStructures data)
{
	std::cout << "STRING: \n" << data.stringTest << std::endl;
	throw std::invalid_argument("Element not found.");
}

void	testRawStringArray(DataStructures data)
{
	unsigned long	length;

	std::cout << "STRING ARRAY: " << std::endl;
	length = sizeof(&data.stringArrayTest) / sizeof(&data.stringArrayTest[0]);
	for (unsigned long i = 0; i != length; i++)
	{
		std::cout << data.stringArrayTest[i] << " ";
	}
    std::cout << std::endl;
    delete [] data.stringArrayTest;
	throw std::invalid_argument("Element not found.");
}

void	testVectorInts(std::vector<int> toTest, int value)
{
	std::cout << "--------------------VECTOR OF INTS: "
				<< std::endl;
	for (std::vector<int>::iterator it = toTest.begin(); it != toTest.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	easyfind(toTest, value);
}

void	testVectorString(std::vector<std::string> str, int value)
{
	(void)value;
	std::cout << "VECTOR OF STRINGS: " << std::endl;
	for (std::vector<std::string>::iterator it = str.begin(); it != str.end(); ++it)
	{
		std::cout << *it << " ";
	}
    std::cout << std::endl;
	throw std::invalid_argument("Element not found.");
}

void	testDeq(std::deque<int> deq, int value)
{
	std::cout << "DEQUE: " << std::endl;
	for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); ++it)
	{
		std::cout << *it << " ";
	}
     std::cout << std::endl;
	(void)value;
	easyfind(deq, value);
}

void	testList(std::list<int> list, int value)
{
	std::cout << "Your chosen data structure list, "
					"contains : "
				<< std::endl;
	for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it)
	{
		std::cout << *it << " ";
	}
    std::cout << std::endl;
	easyfind(list, value);
}
int	main(void)
{
	DataStructures	data;
	int				value;
	int				switchTestNum;

	for (int i = 1; i < 50; i++)
	{
		std::cout << B_ROSE << BOLD << ":::::::::::::::::::::::::::::::::::::::: TEST " << i << " ::::::::::::::::::::::::::::::::::::::::" << RESET << std::endl;
		value = (rand() % 11);
		std::cout << "Value searched for: " << value << std::endl;
		switchTestNum = (rand() % 7) + 1;
		try
		{
			switch (switchTestNum)
			{
			case 1:
				testInt(data.intTest);
				break ;
			case 2:
				testString(data);
				break ;
			case 3:
				testRawStringArray(data);
				break ;
			case 4:
				testVectorInts(data.vectorInt, value);
				break ;
			case 5:
				testVectorString(data.vectorString, value);
				break ;
			case 6:
				testDeq(data.deq, value);
				break ;
			case 7:
				testList(data.lst, value);
				break ; 
            default:
			std::cout << "Invalid option: " << switchTestNum << std::endl;
			break ;
			}
		}
		catch (std::invalid_argument &e)
		{
			std::cout << STRIKE <<  BRIGHT_RED << "Invalid argument caught: " << e.what() << RESET << std::endl;
		}
        catch (std::runtime_error &e)
        {
            std::cout << UNDERLINE << B_BABY_BLUE << "Exception caught: " << e.what() << RESET << std::endl;
        }
		catch (std::exception &e)
		{
			std::cout << STRIKE << BRIGHT_RED << "Error caught: " << e.what() << RESET << std::endl;
		}
	}
}
