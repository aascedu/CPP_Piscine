#include "Fixed.hpp"

Fixed::Fixed() : _i(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed &instance )
{
	*this = instance;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed( const int nbr )
{
	std::cout << "Int constructor called" << std::endl;
	this->_i = nbr << this->_fractionBits;

}

Fixed::Fixed( const float nbr )
{
	std::cout << "Float constructor called" << std::endl;
	this->_i = roundf(nbr * (1 << this->_fractionBits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor Called" << std::endl;
}

std::ostream	&operator<<(std::ostream &ostream, const Fixed &nbr)
{
	std::cout << nbr.toFloat();
	return (ostream);
}

Fixed	&Fixed::operator=(const Fixed &ref)
{
	this->_i = ref._i;
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

bool	Fixed::operator>(const Fixed &nbr) const
{
	if (this->getRawBits() > nbr.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<(const Fixed &nbr) const
{
	if (this->getRawBits() < nbr.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<=(const Fixed &nbr) const
{
	if (this->getRawBits() <= nbr.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator>=(const Fixed &nbr) const
{
	if (this->getRawBits() >= nbr.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator==(const Fixed &nbr) const
{
	if (this->getRawBits() == nbr.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator!=(const Fixed &nbr) const
{
	if (this->getRawBits() == nbr.getRawBits())
		return (true);
	return (false);
}

Fixed	Fixed::operator+(const Fixed &nbr) const
{
	Fixed	add;

	add.setRawBits(this->getRawBits() + nbr.getRawBits());
	return (add);
}

Fixed	Fixed::operator-(const Fixed &nbr) const
{
	Fixed	add;

	add.setRawBits(this->getRawBits() - nbr.getRawBits());
	return (add);
}

Fixed	Fixed::operator*(const Fixed &nbr) const
{
	Fixed	add;

	add.setRawBits(this->getRawBits() * nbr.getRawBits() / (1 << this->_fractionBits));
	return (add);
}

Fixed	Fixed::operator/(const Fixed &nbr) const
{
	Fixed	add;

	add.setRawBits(this->getRawBits() /  nbr.getRawBits() * (1 << this->_fractionBits));
	return (add);
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_i);
}

void Fixed::setRawBits( int const raw )
{
	this->_i = raw;
	std::cout << "setRawBits member function called" << std::endl;
}

float	Fixed::toFloat( void ) const
{
	return ((float)this->_i / (1 << this->_fractionBits));
}

int	Fixed::toInt( void ) const
{
	return (this->_i / (1 << this->_fractionBits));
}