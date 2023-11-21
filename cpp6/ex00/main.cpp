#include "ScalarConverter.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Wrong number of arguments. Must be ./Convert [number]" << std::endl;
		return (1);
	}
	std::string	input = av[1];
	input.erase(0, input.find_first_not_of(" \f\n\t\r\v"));
	input.erase(input.find_last_not_of(" \f\n\t\r\v") + 1);
	try
	{
		ScalarConverter::convert(input);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}