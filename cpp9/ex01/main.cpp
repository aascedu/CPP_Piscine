#include "RPN.hpp"

int	main(int ac, char **av)
{
	if (ac != 2) {
		std::cerr << "exemple : ./RPN \"8 9 * 9 - 9 - 9 - 4 - 1 +\"" << std::endl;
		return (1);
	}
	try
	{
		parsing(av[1]);
		fillStack(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}
	return (0);
}