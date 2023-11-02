#include "Fixed.hpp"

Fixed::Fixed() : _i(0)
{
}

Fixed::Fixed( const Fixed &instance )
{
	*this = instance;
}

Fixed::Fixed( const int nbr )
{
	this->_i = nbr << this->_fractionBits;

}

Fixed::Fixed( const float nbr )
{
	this->_i = roundf(nbr * (1 << this->_fractionBits));
}

Fixed::~Fixed()
{
}

std::ostream	&operator<<(std::ostream &ostream, const Fixed &nbr)
{
	std::cout << nbr.toFloat();
	return (ostream);
}

Fixed	&Fixed::operator=(const Fixed &ref)
{
	this->_i = ref._i;
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

Fixed	&Fixed::operator++()
{
	_i++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp = *this;
	++*this;
	return (temp);
}

Fixed	&Fixed::operator--()
{
	_i--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp = *this;
	--*this;
	return (temp);
}


int Fixed::getRawBits( void ) const
{
	return (_i);
}

void Fixed::setRawBits( int const raw )
{
	this->_i = raw;
}

float	Fixed::toFloat( void ) const
{
	return ((float)this->_i / (1 << this->_fractionBits));
}

int	Fixed::toInt( void ) const
{
	return (this->_i / (1 << this->_fractionBits));
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a._i < b._i)
		return (a);
	else
		return (b);
}

Fixed const	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a._i < b._i)
		return (a);
	else
		return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a._i > b._i)
		return (a);
	else
		return (b);
}

Fixed const	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a._i > b._i)
		return (a);
	else
		return (b);
}