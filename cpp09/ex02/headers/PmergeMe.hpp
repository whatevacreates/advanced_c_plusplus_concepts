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

template <typename T> T startMerge(T &container)
{
	T	new_container;

	typename T::iterator it;
	typename T::iterator it2 = container.begin();
	typename T::iterator mid;
	std::cout << "----- hello: " << std::endl;
	for (it = container.begin(); it != container.end(); ++it)
	{
		++it2;
		std::cout << "it2" << it2 << std::endl;
		typename T::iterator mid = it2;
		++mid;
		it2 = mid;
	}
	std::cout << "checking midpoint: " << *mid << std::endl;
	return (new_container);
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