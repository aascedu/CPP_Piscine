#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	std::deque< int > d;
	std::vector< int > v;
	if (ac < 3) {
		std::cerr << "wrong number of args" << std::endl;
		return (1);
	}
	try
	{
		verifyInput(&av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (2);
	}

	long long timeStart = ft_get_time_ms();
	v = vectorSort(ac, av);
	long long	timeToSortV = ft_get_time_ms() - timeStart;
	if (timeToSortV < 0)
		return (4);

	timeStart = ft_get_time_ms();
	d = dequeSort(ac, av);
	long long timeToSortD = ft_get_time_ms() - timeStart;
	if (timeToSortD < 0)
		return (5);
	std::cout << "After : ";
	for (size_t i = 0; i < d.size(); i++) {
		std::cout << d[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Time to sort using vector container (ms) : " << timeToSortV << std::endl;
	std::cout << "Time to sort using deque container (ms) : " << timeToSortD << std::endl;
}
