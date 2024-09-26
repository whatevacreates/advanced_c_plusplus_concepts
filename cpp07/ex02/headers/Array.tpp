
#include "Array.hpp"

template <typename T> Array<T>::Array() : _len(0), _arrayElem(NULL)
{
}

template <typename T> Array<T>::Array(unsigned int len) : _len(len),
	_arrayElem(new T[len])
{
}

template <typename T> Array<T>::Array(const Array<T> &other) : _len(other._len),
	_arrayElem(new T[other._len])
{
	if (this != &other)
	{
		for (unsigned int i = 0; i < other._len; i++)
		{
			_arrayElem[i] = other._arrayElem[i];
		}
	}
}

template <typename T> Array<T> &Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		_len = other._len;
		delete[] _arrayElem;
		this->_arrayElem = new T[_len];
		for (unsigned int i = 0; i < _len; i++)
			this->_arrayElem[i] = other._arrayElem[i];
	}
	return (*this);
}

template <typename T> unsigned int Array<T>::getSize() const
{
	return (_len);
}

template <typename T> T &Array<T>::operator[](unsigned int index) const
{
	if (index >= getSize())
		throw arrayExceptions();
	return (_arrayElem[index]);
}

template <typename T> Array<T>::~Array()
{
	if (_arrayElem)
		delete[] _arrayElem;
}