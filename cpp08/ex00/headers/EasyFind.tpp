
#include "EasyFind.hpp"
#include "Utils.hpp"

/// this is called: specialised functions 

template <typename T> typename T::const_iterator easyfind(const T &container,
	int value)
{
	typename T::const_iterator it;
	it = find(container.begin(), container.end(), value);
	if (it == container.end())
	{
		throw customException();
	}
	else
	{
		std::cout << BOLD << BRIGHT_GREEN << "::::::::::::::::::::::::::::::: Yay, "
			"Element Found! :::::::::::::::::::::::::::::::" << RESET << std::endl;
	}
	return (it);
}

template <typename T, size_t N> int *easyfind(T (&array)[N], int value)
{
	for (size_t i = 0; i < N; ++i)
	{
		if (array[i] == value)
		{
			std::cout << BOLD << B_PASTEL_GREEN << "::::::::::::::::::::::::::::::: Yay, "
				"Element Found! :::::::::::::::::::::::::::::::" << RESET << std::endl;
			return (&array[i]);
		}
	}
	throw customException();
}
