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
		Array<T>(const Array<T> &ref);
		Array<T>(unsigned int n);
		Array<T>	&operator=( const Array<T> &ref );
		T	&operator[]( unsigned int i );
		T	&operator[]( unsigned int i ) const;
		class OutOfBoundsException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
		unsigned int	size( void ) const;
};

# include "Array.tpp"

#endif