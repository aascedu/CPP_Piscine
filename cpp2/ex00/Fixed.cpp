#include "Fixed.hpp"

Fixed::Fixed() : i(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed &instance )
{
	*this = instance;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &ref)
{
	this->i = ref.i;
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor Called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (i);
}

void Fixed::setRawBits( int const raw )
{
	this->i = raw;
	std::cout << "setRawBits member function called" << std::endl;
}
