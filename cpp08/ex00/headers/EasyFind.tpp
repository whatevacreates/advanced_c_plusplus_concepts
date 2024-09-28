
#include "EasyFind.hpp"

template<typename T>
typename T::const_iterator easyfind(const T& container, int value)
{

    typename T::const_iterator it;
    it = find(container.begin(), container.end(), value);
    if(it == container.end())
    {
        throw std::runtime_error("Element not found");
    }
    return it;
}

template<typename T>
void easyfind(const T&, int value)
{
    (void)value;
    throw std::runtime_error("Not supported frormat");
}