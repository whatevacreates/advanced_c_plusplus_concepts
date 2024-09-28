#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include "Utils.hpp"
#include "EasyFind.hpp"



int main()
{
    int array[] = {1, 2, 3, 4, 5};
    int length = sizeof(array[0]/sizeof(array));
    std::vector<int> vectorInt;
    vectorInt.assign(array, array + length);
    int b = 40;
    std::cout << B_ROSE << BOLD << ":::::::::::::::::::::::::::::::::::::::: TEST 1: INT VECTOR ::::::::::::::::::::::::::::::::::::::::" << RESET << std::endl;
    try
    {
        if(typeid(vectorInt) == typeid(std::vector<int>))
        {
            easyfind(vectorInt, b);
        }
        else
        {
            throw std::runtime_error("The first argument is not the container of intergers");
            std::cout << ITALIC << B_BABY_BLUE << "Test with container of integers" << RESET << std::endl;
        }
            
        std::cout << "success" << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
   std::cout << B_ROSE << BOLD << ":::::::::::::::::::::::::::::::::::::::: TEST 2: ARRAY ::::::::::::::::::::::::::::::::::::::::" << RESET << std::endl;
    try
    {
        if(typeid(array) == typeid(std::vector<int>))
        {
            easyfind(array, b);
        }
        else
        {
            throw std::runtime_error("The first argument is not the container of intergers");
            std::cout << ITALIC << B_BABY_BLUE << "Test with container of integers" << RESET << std::endl;
        }
          
        std::cout << "success" << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}
