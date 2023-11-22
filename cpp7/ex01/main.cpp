#include "iter.hpp"
#include <iostream>

int	main(void)
{
	int	array[5] = {1,2,3,4,5};
	std::string string_array[4] = {"hey", "test", "1234567899", "Arthur"};

	::iter(array, 5, ::printData);
	::iter(string_array, 4, ::printData);
}