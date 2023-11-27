#include <iostream>
#include "iter.hpp"

void	printInt( const int arg )
{
	std::cout << arg << "_iter" << std::endl;
}

void	printStr( const std::string arg )
{
	std::cout << arg << "_iter" << std::endl;
}

int	main(void)
{
	int	array[5] = {1,2,3,4,5};
	std::string string_array[4] = {"hey", "test", "1234567899", "Arthur"};

	iter(array, 5, printInt);
	iter(string_array, 4, printStr);
}