#include "PmergeMe.hpp"
#include "Utils.hpp"

Pmerge::Pmerge()
{
}

Pmerge::Pmerge(std::string str)
{
	std::cout << "string: " << str << std::endl;
	
}



Pmerge::Pmerge(const Pmerge &other) 
{
	(void)other;
}

Pmerge &Pmerge::operator=(const Pmerge &other)
{
	(void)other;
	return (*this);
}

Pmerge::~Pmerge()
{
}

void Pmerge::runTests(std::string str)
{

mergeSort(_deq, str);
	mergeSort(_list, str);

}

std::list<int> Pmerge::getList() const
{
		return _list;
}

std::deque<int> Pmerge::getDeq() const
{
		return _deq;
}

/*
std::ostream &operator<<(std::ostream &out, const Pmerge &src)
{
	return out << ;
}
*/