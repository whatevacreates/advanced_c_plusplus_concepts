#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <exception> 

template<typename T>
typename T::const_iterator easyfind(const T& container, int value);
template<typename T>
void easyfind(const T&, int value);

#include "EasyFind.tpp"

#endif