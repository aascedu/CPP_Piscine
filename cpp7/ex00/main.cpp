#include <iostream>
#include "Template.hpp"


int	main(void)
{
	std::string	a = "chaine1";
	std::string	b = "chaine2";

	std::cout << ::min(a, b) << std::endl;
	std::cout << "a: " << a << " b: " << b << std::endl;
	::swap(a, b);
	std::cout << "a: " << a << " b: " << b << std::endl;
	std::cout << ::min(a, b) << std::endl;

	int	c = 1;
	int	d = 7;

	std::cout << ::min(c, d) << std::endl;
	std::cout << "c: " << c << " d: " << d << std::endl;
	::swap(c, d);
	std::cout << "c: " << c << " d: " << d << std::endl;
	std::cout << ::max(c, d) << std::endl;
}