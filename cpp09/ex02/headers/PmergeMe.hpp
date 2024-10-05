#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <algorithm>
# include <ctime>
# include <deque>
# include <exception>
# include <iomanip>
# include <iostream>
# include <limits>
# include <list>
# include <ostream>
# include <sstream>
# include <string>
# include <utility>

template <typename T> void merge(T &left, T &right, T &result)
{
	typename T::iterator it_left = left.begin();
	typename T::iterator it_right = right.begin();
	while (it_left != left.end() && it_right != right.end())
	{
		if (*it_left <= *it_right)
		{
			result.push_back(*it_left);
			++it_left;
		}
		else
		{
			result.push_back(*it_right);
			++it_right;
		}
	}
	while (it_left != left.end())
	{
		result.push_back(*it_left);
		++it_left;
	}
	while (it_right != right.end())
	{
		result.push_back(*it_right);
		++it_right;
	}
}

template <typename T> void recursiveMergeSort(T &container)
{
	int	size;

	size = container.size();
	if (size <= 1)
		return ;
	T left, right;
	typename T::iterator it = container.begin();
	for (int i = 0; i < size / 2; ++i)
	{
		left.push_back(*it);
		++it;
	}
	while (it != container.end())
	{
		right.push_back(*it);
		++it;
	}
	recursiveMergeSort(left);
	recursiveMergeSort(right);
	container.clear();
	merge(left, right, container);
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
		if (data >= 2147483647)
		{
			std::cerr << "Error: number > " << std::numeric_limits<int>::max() << " detected" << std::endl;
			exit(1);
		}
		container.push_back(data);
	}
	if (container.size() == 1)
	{
		std::cout << "Input is already sorted, contains one number, "
			"ciao :D" << std::endl;
		exit(0);
	}
	recursiveMergeSort(container);
	std::cout << "Sorted numbers: ";
	for (typename T::iterator it = container.begin(); it != container.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
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
	long long int getTime();
	void runTests(std::string str);
	void recursiveMergeSortDeque(std::deque<int> &container);
	void mergeDeque(std::deque<int> &left, std::deque<int> &right,
		std::deque<int> &result);
	void recursiveMergeSortList(std::list<int> &container);
	void mergeList(std::list<int> &left, std::list<int> &right,
		std::list<int> &result);
};

std::ostream &operator<<(std::ostream &out, const Pmerge &src);
#endif