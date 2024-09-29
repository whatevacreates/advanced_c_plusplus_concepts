#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <deque>
# include <exception>
# include <iostream>
# include <list>
# include <string>
# include <tuple>
# include <vector>

struct			DataStructures
{
	int			intTest;
	std::string stringTest;
	std::string *stringArrayTest;
	std::vector<int> vectorInt;
	std::vector<std::string> vectorString;
	std::deque<int> deq;
	std::list<int> lst;
	std::pair<int, std::string> tupleCollection;

	DataStructures() : intTest(1), stringTest("This is some string"),
		tupleCollection(3, "apple")
	{
		size_t	number_of_elements = 5;
		stringArrayTest = new std::string[5];

		for (size_t i = 0; i < number_of_elements; i++)
		{
			vectorInt.resize(i + 1);
			vectorString.resize(i + 1);
			vectorInt[i] = (rand() % 11);
			deq.push_back(rand() % 11);
			lst.push_back(rand() % 11);
			vectorString[i] = "VectorArrayElement: " + std::to_string(i * 2);
			stringArrayTest[i] = "RawArrayElement: " + std::to_string(i * 2);
		}
	}
};

struct customException : public std::runtime_error
{
  public:
	customException() : std::runtime_error("Element not found custom information")
	{
	}
};

template <typename T> typename T::const_iterator easyfind(const T &container,
	int value);
template <typename T, size_t N> int *easyfind(T (&array)[N], int value);

# include "EasyFind.tpp"

#endif