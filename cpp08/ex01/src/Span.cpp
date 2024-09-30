#include "Span.hpp"

Span::Span() : _max(0)
{
}

Span::Span(long long int max) : _max(max)
{
}

Span::Span(const Span &other) : _bank(other._bank), _max(other._max),
{
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_max = other._max;
		_bank = other._bank;
	}
	return (*this);
}

Span::~Span()
{
}

void Span::addNumber(long long int number)
{
	try
	{
		if ((long long int)_bank.size() >= _max)
		{
			throw std::runtime_error("The bank is already FULL.");
		}
		_bank.insert(number);
	}
	catch (std::runtime_error &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void	shortestSpan(void)
{
	long long int	temp;
	long long int	min;
	long long int	length;

	min = MAX_INT;
	std::set<long long int>::const_iterator it;
	try
	{
		if (_bank.size() <= 1)
		{
			throw std::runtime_error("The bank is too small to proceed.");
		}
		length = (sizeof(_bank)) / sizeof(_bank[0]);
		min = std::numeric_limits<long long int>::max();
		for (it = std::next(_bank.begin()); it != _bank.end(); ++it)
		{
			temp = *it - (--*it);
			if (min > temp)
			{
				min = temp;
			}
		}
		std::cout << min << std::endl;
	}
	catch (std::runtime_error &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

long long int Span::longestSpan() const
{
	std::cout << *(_bank.end()) - *(_bank.begin()) << std::endl;
}