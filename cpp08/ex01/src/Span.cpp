#include "Span.hpp"

Span::Span() : _max(0)
{
}

Span::Span(long long int max) : _max(max)
{
}

Span::Span(const Span &other) : _bank(other._bank), _max(other._max)
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
	if ((long long int)_bank.size() >= _max)
	{
		throw std::runtime_error("The bank of numbers is already FULL.");
	}
	_bank.insert(number);
}

long long int Span::shortestSpan(void) const
{
    if (_bank.size() <= 1)
    {
        throw std::runtime_error("The bank of numbers is too small to proceed.");
    }

    long long int min = std::numeric_limits<long long int>::max();
    std::set<long long int>::const_iterator it = _bank.begin();
    std::set<long long int>::const_iterator next_it = it;
    ++next_it;

    while (next_it != _bank.end())
    {
        long long int temp = *next_it - *it;
        if (temp < min)
        {
            min = temp;
        }
        ++it;
        ++next_it;
    }

    return min;
}

long long int Span::longestSpan() const
{
    if (_bank.size() <= 1)
    {
        throw std::runtime_error("The bank of numbers is too small to proceed.");
    }

    return *(--_bank.end()) - *(_bank.begin());
}
