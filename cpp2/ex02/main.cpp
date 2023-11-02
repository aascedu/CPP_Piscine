#include "Fixed.hpp"
#include <iostream>

int main( void )
{
	Fixed		a;
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;
	
	Fixed	c(3), d(10000);

	std::cout << "Min and Max with Int and Float" << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << Fixed::min( c, d ) << std::endl;
	
	std::cout << "+ : ";
	std::cout << a + b << std::endl;

	std::cout << "- : ";
	std::cout << a - b << std::endl;

	std::cout << "* : ";
	std::cout << a * b << std::endl;

	std::cout << "/ : ";
	std::cout << a / b << std::endl;

	return 0;
}