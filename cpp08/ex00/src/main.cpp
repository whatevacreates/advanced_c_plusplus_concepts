#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include "Utils.hpp"
#include "Easyfind.hpp"


template<typename T>
T& easyfind(T a, int b)
{

    typename T::iterator i;
    for(i = a.begin(); a.begin() != a.end(); ++i) 
    {
        if(*i == b)
        {
            std::cout << i << " is equal: " << b << std::endl;
            return i;
        }
        
    }
    throw std::runtime_error("Element not found");

return i;
}

int main()
{
    int array[] = {1, 2, 3, 4, 5};
    int length = sizeof(array[0]/sizeof(array));
    std::vector<int> vectorInt;
    vectorInt.assign(array, array + length);
    int b = 4;
    try
    {
        easyfind(vectorInt, b);
    }
    catch(std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
}