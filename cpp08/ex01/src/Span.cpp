#include "Span.hpp"

Span::Span():bank(NULL)
{}

Span::Span(long long int max): _max(max)
{

}

void Span::addNumber(long long int &number)
{
    try
    {
         if(bank.size() >= _max)
    {
        throw std::runtime_error("The bank is already FULL.")
    }
    _bank.push_back(&number);
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

void shortestSpan()
{
    long long int temp;
    long long int min = MAX_INT;
    std::deque<int>::const_iterator it;
     try
    {
         if(bank.size() <= 1)
    {
        throw std::runtime_error("The bank is too small to proceed.")
    }
    long long int length = (sizeof(_bank))/sizeof(_bank[0]);
min =  temp = _bank[i] - _bank[i-1];
    for(it = _bank.begin()++; i < _bank.end(); it++)
    {
        temp = *it - (--*it);
if(min > temp)
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

void Span::longestSpan()
{
    std::cout << _bank.end() - _bank.begin() << std::endl;
}