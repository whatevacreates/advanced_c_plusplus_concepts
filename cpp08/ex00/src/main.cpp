#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include "Utils.hpp"
#include "Easyfind.hpp"


template<typename T>
typename T::const_iterator easyfind(const T& container, int value)
{

    typename T::iterator it;
    it = find(container.begin(), container.end(), value);
    if(it == container.end())
    {
        throw std::runtime_error("Element not found");
    }
    return it;
}

int main()
{
    int array[] = {1, 2, 3, 4, 5};
    int length = sizeof(array[0]/sizeof(array));
    std::vector<int> vectorInt;
    vectorInt.assign(array, array + length);
    int b = 90;
    try
    {
        easyfind(vectorInt, b);
    }
    catch(std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
}