#include "Harl.hpp"

int	main(void)
{
	Harl	test;

	test.complain("WARNING");
	test.complain("DEBUG");
	test.complain("ERROR");
	test.complain("INFO");
	return (0);
}