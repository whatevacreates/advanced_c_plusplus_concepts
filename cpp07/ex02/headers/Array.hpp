#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>
# include <iostream>
# include <string>

template <typename T> class Array
{
  private:
	unsigned int _len;
	T *_arrayElem;

  public:
	Array();
	Array(unsigned int len);
    Array(const Array &other);
	Array<T>& operator=(const Array &other);
	T& operator[](unsigned int index) const;
	~Array();
	class arrayExceptions : public std::exception
	{
		public:
		const char* what() const _NOEXCEPT
		{
			return "Throwing a fancy customised OUT OF BOUNDS exception::::..";
		}
	};
	unsigned int getSize() const;
};

# include "Array.tpp"
#endif 