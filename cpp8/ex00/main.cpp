#include "easyfind.hpp"
#include <iostream>

int	main(void)
{
	const std::string a = "v/usr/bin/../lib/gcc/x86_64-linux-gnu/10/../../../../include/c++/10/bits/basic_string.h:500:7: note: candidate constructor not viable: requires 4 arguments, but 1 was provided";
	std::cout << easyfind(a, '+') << std::endl;
}