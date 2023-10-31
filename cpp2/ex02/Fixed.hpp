#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					_i;
		static const int	_fractionBits = 8;
	public:
		Fixed();
		Fixed( const Fixed &instance );
		Fixed( const int nbr );
		Fixed( const float nbr );
		~Fixed();
		int 	getRawBits( void ) const;
		void 	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
		Fixed	&operator=(const Fixed &ref);
		Fixed	operator*(const Fixed &nbr) const;
		Fixed	operator/(const Fixed &nbr) const;
		Fixed	operator+(const Fixed &nbr) const;
		Fixed	operator-(const Fixed &nbr) const;
		bool	operator>(const Fixed &nbr) const;
		bool	operator<(const Fixed &nbr) const;
		bool	operator<=(const Fixed &nbr) const;
		bool	operator>=(const Fixed &nbr) const;
		bool	operator==(const Fixed &nbr) const;
		bool	operator!=(const Fixed &nbr) const;
};

std::ostream	&operator<<(std::ostream &ostream, const Fixed &nbr);

#endif