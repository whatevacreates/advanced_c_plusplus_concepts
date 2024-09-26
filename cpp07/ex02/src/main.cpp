
#include "Array.hpp"

void	runBasic(void)
{
	Array<float> *basicArray = new Array<float>(3);
	for (int i = 0; i < 3; i++)
	{
		(*basicArray)[i] = i * 1.32;
	}
	for (int i = 0; i < 3; i++)
	{
		std::cout << (*basicArray)[i] << std::endl;
	}
	delete (basicArray);
}

void	runCopyAssignmentOperator(void)
{
	Array<std::string> *strArray1 = new Array<std::string>(3);
	Array<std::string> *strArray2 = new Array<std::string>();
	for (int i = 0; i < 3; i++)
	{
		(*strArray1)[i] = "Element" + std::to_string(i);
	}
	*strArray2 = *strArray1;
	for (int i = 0; i < 3; i++)
	{
		std::cout << "strArray2 element: " << i << ": " << (*strArray2)[i] << std::endl;
	}
	std::cout << "-------------- modifying first element of the original array --------------" << std::endl;
	(*strArray1)[0] = "ELEMENT CHANGED";
	for (int i = 0; i < 3; i++)
	{
		std::cout << "strArray1 element: " << i << ": " << (*strArray1)[i] << std::endl;
		std::cout << "strArray2 element: " << i << ": " << (*strArray2)[i] << std::endl;
	}
	std::cout << "Testing an out of bounds index for the Array:" <<std::endl;
	try
	{
		std::cout << (*strArray1)[-302043242] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	delete (strArray1);
	delete (strArray2);
}

void	runOutOfBands(void)
{
	int	size;

	size = 10;
	Array<bool> *boolArray = new Array<bool>(size);
	for (int i = 0; i < size; i++)
	{
		(*boolArray)[i] = (i % 2 == 0);
	}
	for (int i = 0; i < size; i++)
	{
		std::cout << ((*boolArray)[i] % 2 ? "true" : "false") << std::endl;
	}
	try
	{
		std::cout << "Testing an out of bounds index for the Array:" <<std::endl;
		std::cout << (*boolArray)[size + 10] << std::endl;
	}
	
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	delete (boolArray);
}

int	main(void)
{
	std::cout << "::::::::::::::::::::::::::::::::::::::::::::::: BASIC TEST | FLOAT ::::::::::::::::::::::::::::::::::::::::::::::::" << std::endl;
	runBasic();
	std::cout << std::endl;
	std::cout << ":::::::::::::::::::::::::::::::::::::: COPY ASSIGNMENT OPERATOR TEST | STD::STRING ::::::::::::::::::::::::::::::::::::::" << std::endl;
	runCopyAssignmentOperator();
	std::cout << std::endl;
	std::cout << ":::::::::::::::::::::::::::::::::::::::::::: OUT OF BOUNDS TEST | BOOL ::::::::::::::::::::::::::::::::::::::::::::" << std::endl;
	runOutOfBands();
	std::cout << std::endl;
}