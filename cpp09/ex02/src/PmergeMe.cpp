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


/*
std::ostream &operator<<(std::ostream &out, const Pmerge &src)
{
	return out << ;
}
*/