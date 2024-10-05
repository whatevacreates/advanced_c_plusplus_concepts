#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <algorithm>
# include <deque>
# include <exception>
# include <iostream>
# include <limits>
# include <list>
# include <ostream>
# include <sstream>
# include <string>
# include <utility>

template <typename T> void recursiveMergeSort(T &left, T &right)
{
	int	size;
	T	new_left;
	T	new_right;
	T	new_container;
	int	i;

	typename T::iterator it_left = left.begin();
	typename T::iterator it_right = right.begin();
	size = left.size();
	if (size > 1)
	{
		for (i = 0; i < size / 2; i++)
		{
			new_left.push_back(*(it_left++));
		}
		while (i < size)
		{
			new_right.push_back(*(it_left++));
			i++;
		}
		recursiveMergeSort(new_left, new_right);
	}

	for (int i = 0; i < size * 2; i++)
	{
		it_left = left.begin();
		it_right = right.begin();
		if (*it_left < *it_right)
		{
			
			new_container.push_back(*it_left);
			left.pop_front();
		}
		else
		{
			
			new_container.push_back(*it_right);
			right.pop_front();
		}
	}
}

template <typename T> T startMerge(T &container)
{
	T	left;
	T	right;
	int	size;
	int	i;

	size = container.size();
	typename T::iterator it_left = container.begin();
	typename T::iterator it_right = container.begin();
	for (i = 0; i < size / 2; i++)
	{
		left.push_back(*(it_left++));
	}
	while (i < size)
	{
		right.push_back(*(it_right++));
		i++;
	}
	recursiveMergeSort(left, right);
	for (typename T::iterator it2 = left.begin(); it2 != left.end(); ++it2)
	{
		std::cout << "left: " << *it2 << " ";
	}
	for (typename T::iterator it3 = right.begin(); it3 != right.end(); ++it3)
	{
		std::cout << "right: " << *it3 << " ";
	}
	std::cout << std::endl;
	return (container);
}

template <typename T> void mergeSort(T &container, std::string str)
{
	int	data;

	for (size_t i = 0; i < str.length(); i++)
	{
		while (i < str.size() && str[i] == ' ')
			i++;
		std::string temp;
		while (i < str.size() && str[i] != ' ')
		{
			temp += str[i];
			i++;
		}
		if (temp.empty())
		{
			break ;
		}
		std::stringstream ss(temp);
		ss >> data;
		ss.clear();
		container.push_back(data);
	}
	container = startMerge(container);
}

class Pmerge
{
  private:
	std::list<int> _list;
	std::deque<int> _deq;

  public:
	Pmerge();
	Pmerge(std::string str);
	~Pmerge();
	Pmerge(const Pmerge &other);
	Pmerge &operator=(const Pmerge &other);
	std::deque<int> getDeq() const;
	std::list<int> getList() const;
	void runTests(std::string str);
};

std::ostream &operator<<(std::ostream &out, const Pmerge &src);
#endif