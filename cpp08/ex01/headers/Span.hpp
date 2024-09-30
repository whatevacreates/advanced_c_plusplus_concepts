#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <string>
#include <set>

class Span
{
    private:
    std::set<long long int> _bank;
    long long int _max;
    public:
    Span();
    Span(long long int max);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();
    void addNumber(long long int number);

   long long int shortestSpan() const;
    long long int longestSpan() const;
    
};

#endif