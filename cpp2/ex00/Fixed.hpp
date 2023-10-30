#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int					i;
		static const int	fractionBits = 8;
	public:
		Fixed();
		Fixed( const Fixed &instance );
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		Fixed	&operator=(const Fixed &ref);
};

#endif