// fwewf
#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac != 2) {
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}
	std::ifstream	infile(av[1]);
	std::string	content;
	while (!infile.eof())
		content + infile.get
	std::cout << content << std::endl;
	return (0);
}