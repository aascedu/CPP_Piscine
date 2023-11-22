#include <iostream>
#include "Template.hpp"


int	main(void)
{
	std::string	a = "chaine1";
	std::string	b = "chaine2";

	std::cout << ::min(a, b) << std::endl;
	::swap(a, b);
	std::cout << "a: " << a << " b: " << b << std::endl;
	std::cout << ::min(a, b) << std::endl;
}