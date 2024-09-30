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

long long int Span::shortestSpan() const
{
    if (_bank.size() <= 1)
    {
        throw std::runtime_error("The bank of numbers is too small to proceed.");
    }

    std::vector<long long int> diffs(_bank.size());
    
    std::adjacent_difference(_bank.begin(), _bank.end(), diffs.begin());
    
    return *std::min_element(diffs.begin() + 1, diffs.end());
}

long long int Span::longestSpan() const
{
    if (_bank.size() <= 1)
    {
        throw std::runtime_error("The bank of numbers is too small to proceed.");
    }

    return *(--_bank.end()) - *(_bank.begin());
}
