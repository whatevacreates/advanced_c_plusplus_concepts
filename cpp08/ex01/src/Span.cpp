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

long long int	Span::shortestSpan(void) const
{
	long long int	temp;
    long long int min = 0;

	std::set<long long int>::const_iterator it;
	try

	{
		if (_bank.size() <= 1)
		{
			throw std::exception "The bank is too small to proceed." ;

		}
		min = std::numeric_limits<long long int>::max();
		for (it = std::next(_bank.begin()); it != _bank.end(); ++it)
		{
			temp = *it - *(std::prev(it));
			if (min > temp)
			{
				min = temp;
			}
		}
		
        return min;
	}
	catch (std::runtime_error &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
    return min;
}
long long int Span::longestSpan() const
{
	
    return  *(std::prev(_bank.end())) - *(_bank.begin());
}

template<typename T>
void Span::addRange(T a, T b)
{
    try{
        for(T it = a; it != b; ++it)
        {
addNumber(*it);
        }
       
    }
    catch(const std::exception& e)
    {
        std::cout << "Error caught: " << e.what() << std::endl;
    }

}