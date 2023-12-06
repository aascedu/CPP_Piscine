#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	if (ac < 3) {
		std::cerr << "wrong number of args" << std::endl;
		return (1);
	}
	try
	{
		verifyInput(&av[1]);
		dequeSort(ac, av);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (2);
	}
	
}