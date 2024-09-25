
#include "Array.hpp"

// Default Constructor
template <typename T>
Array<T>::Array() : _n(0), _arrayOfElements(NULL) {}

// Parameterized Constructor
template <typename T>
Array<T>::Array(unsigned int n) : _n(n), _arrayOfElements(new T[n]) {}

// Copy Constructor
template <typename T>
Array<T>::Array(const Array& other) : _n(other._n), _arrayOfElements(new T[other._n]) {
    for (unsigned int i = 0; i < _n; i++) {
        _arrayOfElements[i] = other._arrayOfElements[i]; // Deep copy of elements
    }
}

// Assignment Operator
template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) { // Avoid self-assignment
        delete[] _arrayOfElements; // Delete existing memory
        _n = other._n; // Copy size
        _arrayOfElements = new T[_n]; // Allocate new memory
        for (unsigned int i = 0; i < _n; i++) {
            _arrayOfElements[i] = other._arrayOfElements[i]; // Copy elements
        }
    }
    return *this;
}

// Destructor
template <typename T>
Array<T>::~Array() {
    delete[] _arrayOfElements; // Free allocated memory
}

// Overloaded Subscript Operator
template <typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= _n) {
        throw std::out_of_range("Index out of range");
    }
    return _arrayOfElements[index];
}

// Size Function
template <typename T>
unsigned int Array<T>::size() const {
    return _n;
}
