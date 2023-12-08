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

	struct timeval	startTime;
	if (gettimeofday(&startTime, NULL) < 0)
		return (3);

	v = vectorSort(ac, av);
	int	timeToSortV = getTime(startTime);
	if (timeToSortV < 0)
		return (4);

	struct timeval	startTime;
	if (gettimeofday(&startTime, NULL) < 0)
		return (3);
	d = dequeSort(ac, av);
	int timeToSortD = getTime(startTime);
	if (timeToSortD < 0)
		return (5);
	std::cout << "After : ";
	for (size_t i = 0; i < d.size(); i++) {
		std::cout << d[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Time to sort using vector container : " << timeToSortV << std::endl;
	std::cout << "Time to sort using deque container : " << timeToSortD << std::endl;
}