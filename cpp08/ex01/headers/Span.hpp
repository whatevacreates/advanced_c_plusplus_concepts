#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <string>

class Span
{
    private:
    std::set<int> _bank;
    long long int _max;
    public:
    Span();
    Span(long long int max);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();
    void addNumber(long long int number);

    void shortestSpan();
    void longestSpan();
    struct checkCapacity : public std::exception
    {
        public:
        const char* what() const throw{
            return ("There is no more capacity.");
        }
    }
};

#endif