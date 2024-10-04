#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <exception>
#include <ostream>
# include <iostream>
# include <limits>
# include <sstream>
# include <string>
#include <list>
#include <deque>
#include <utility>
#include <algorithm>


template<typename T>

template<typename T>
T<int>& startMerge(T<int>& container)
{
	std::T<int>::iterator it;
	std::T<int> new_container;

	for(it = container.begin(); it++ != container.end(); it + 2 )
	{
		if(it > it++)
		{
			new_container.push_back(it);
			new_container.push_back(++it);
		}
		else
		{
			new_container.push_back(++it);
			new_container.push_back(it);
		}

	}




template<typename T>
void mergeSort(T<int>& container, std::string str)
{
int data;
std::string temp;

for(int i = 0; str[i] != '\0'; i++)
{

while(str[i] == ' ' && str[i] != '\0')
i++;

int k = 0;
while(str[i] != ' ' && str[i] != '\0')
{
	temp[k] = str[i];
i++;
}
str[i] = '\0';
std::streamstring ss(str);
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

};

std::ostream& operator<<(std::ostream& out, const Pmerge& src);
#endif