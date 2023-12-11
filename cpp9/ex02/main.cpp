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

	clock_t	vStartTime = clock();
	v = vectorSort(ac, av);
	clock_t	vEndTime = clock();

	clock_t	dStartTime = clock();
	d = dequeSort(ac, av);
	clock_t	dEndTime = clock();
	std::cout << "After : ";
	for (size_t i = 0; i < d.size(); i++) {
		std::cout << d[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Time to sort using vector container : " << (vEndTime - vStartTime) / 1000 << " ms" << std::endl;
	std::cout << "Time to sort using deque container : " << (dEndTime - dStartTime) / 1000 << " ms" << std::endl;
}
