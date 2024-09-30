#include "MutantStack.hpp"

template<typename T>
MutantStack::MutantStack(): std::stack<T>()
{}

template<typename T>
MutantStack::MutantStack(const MutantStack& other): std::stack<T>(other)
{}

template<typename T>
MutantStack& MutantStack::operator=(const MutantStack& other)
{
    if(this != &other)
    {
        std::stack<T>::operator=(other);
    }
   return *this;

}

template<typename T>
MutantStack::~MutantStack()
{}

template<typename T>
MutantStack::iterator begin()
{
    return this->c.begin();
}

template<typename T>
MutantStack::iterator end()
{
    return this->c.end();
}

template<typename T>
MutantStack::const_iterator begin() const
{
    return this->c.begin();
}

template<typename T>
MutantStack::const_iterator end() const
{
    return this->c.end();
}