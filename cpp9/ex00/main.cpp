#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac != 2) {
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}
	std::ifstream	infile(av[1]);
	if (!infile.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}
	std::string line;
	while (std::getline(infile, line))
		std::cout << line << std::endl;
	return (0);
}