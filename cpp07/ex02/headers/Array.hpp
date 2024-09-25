#ifndef ARRAY_TPP
#define ARRAY_TPP

#include <stdexcept>
#include <exception>
#include <iostream>

template<typename T>
class Array
{
    private:
    unsigned int _n;
    T *_arrayOfElements;

    public:
    Array();

    Array(unsigned int n);
    Array(const Array& other);
    Array& operator=(const Array& other);

    ~Array();
    T& operator[](unsigned int index);
    unsigned int size() const;

};

#include "Array.tpp"

#endif