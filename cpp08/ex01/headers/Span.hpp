#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <set>
# include <string>
# include <vector>

class Span
{
  private:
	std::set<long long int> _bank;
	long long int _max;

  public:
	Span();
	Span(long long int max);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();
	void addNumber(long long int number);

	long long int shortestSpan() const;
	long long int longestSpan() const;
	template <typename T> void addRange(T a, T b)
	{
		for (T it = a; it != b; ++it)
		{
			if ((long long int)_bank.size() >= _max)
			{
				throw std::runtime_error("The bank of numbers is already FULL.");
			}
			addNumber(*it);
		}
	}
};

#endif