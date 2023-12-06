#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac != 2) {
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}
	try
	{
		parsing(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}
	return (0);
}