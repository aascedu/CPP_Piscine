#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array
{
	private:
		T				*_array;
		unsigned int	_size;
	public:
		Array<T>();
		~Array<T>();
		Array<T>(unsigned int n);
};

#endif