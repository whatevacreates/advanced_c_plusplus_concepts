#include <iostream>
#include <algorithm>
#include <string>
#include "Utils.hpp"
#include "Easyfind.hpp"


template<typename T>
T& easyfind(T a, int b)
{
try
{
    typename T::iterator i;
    for(int i = a.begin(); a.begin() != a.end(); i++) 
    {
        if(i == b)
        {
            std::cout << i << " is equal: " << b << std::endl;
            return a;
        }
        
    }
    throw std::exception;
} catch(std::exception &e)
{
std::cout << "exception caught: " << e.what() << std::endl;
}  
return a;
}

int main()
{
    std::vector verctorIntS[6] = {1, 2, 3, 4, 5};
    int b = 4;
    easyfind(vactorIntS, b);
}