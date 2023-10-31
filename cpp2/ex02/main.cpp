#include "Fixed.hpp"
#include <iostream>

int main( void )
{
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 0.f );

	std::cout << "HEY : " << --a << std::endl;
	std::cout << "ICI : " << a << std::endl;
	if (b >= a)
		std::cout << " Hey" << std::endl;
	return 0;
}