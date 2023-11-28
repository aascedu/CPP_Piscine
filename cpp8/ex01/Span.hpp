#ifndef SPAN_HPP
# define SPAN_HPP

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

class Span
{
	private:
		std::vector<int>	_container;
		unsigned int		_N;
	public:
		Span( unsigned int N );
		~Span();
		Span( const Span &ref );
		Span	&operator=( const Span &ref );
		void	addNumber( const int nbr );
		class ArrayIsFullException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
		class WrongSizeException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
		int		shortestSpan( void );
		int		longestSpan( void );
		void	fillContainer(unsigned int size, int nbr);

};

#endif