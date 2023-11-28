#include "Span.hpp"

Span::Span( unsigned int N ) : _N(N)
{
}

Span::~Span()
{
}

Span::Span( const Span &ref ) : _N( ref._N )
{
	this->_container = ref._container;
}

Span	&Span::operator=( const Span &ref )
{
	if (this == &ref)
		return (*this);
	this->_container = ref._container;
	this->_N = ref._N;
	return (*this);
}

void	Span::addNumber( const int nbr )
{
	if (this->_container.size() >= this->_N)
		throw Span::ArrayIsFullException();
	this->_container.push_back(nbr);
}

const char	*Span::ArrayIsFullException::what() const throw() {
	return ("Array is full.");
}

const char	*Span::WrongSizeException::what() const throw() {
	return ("Wrong size.");
}

int	Span::longestSpan( void )
{
	int	max;
	int	min;

	if (_container.size() <= 1)
		throw Span::WrongSizeException();
	max = *std::max_element(this->_container.begin(), this->_container.end());
	min = *std::min_element(this->_container.begin(), this->_container.end());
	return (max - min);
}

int	Span::shortestSpan( void )
{
	std::vector<int>			copy = this->_container;
	std::vector<int>::iterator	copyIt;
	int min = abs(copy[0] - copy[1]);

	if (_container.size() <= 1)
		throw Span::WrongSizeException();
	std::sort(copy.begin(), copy.end());
	for (copyIt = copy.begin() + 1; copyIt != copy.end(); ++copyIt)
	{
		if (min > abs(*(copyIt - 1) - *(copyIt)))
			min = abs(*(copyIt - 1) - *(copyIt));
	}
	return (min);
}

void	Span::fillContainer(unsigned int size, int nbr)
{
	if (_container.size() + size - 1 >= _N)
		throw Span::ArrayIsFullException();
	_container.insert(_container.end(), size, nbr);
}