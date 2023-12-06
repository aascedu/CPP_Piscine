#include "PmergeMe.hpp"

void	verifyInput(char **av)
{
	int i = 0;

	while (av[i])
	{
		std::string s = av[i];
		std::istringstream	ss(s);
		int	value;

		ss >> value;
		if (!ss.eof() || ss.fail())
			throw std::invalid_argument("value isn't an int.");
		if (value < 0) {
			std::cerr << value; 
			throw std::invalid_argument(" this number is negative.");
		}
		i++;
	}
}

void	dequeSort(int ac, char **av)
{
	std::deque< std::pair<int, int> > d;
	int i = 1;

	while (i < ac - 1) {
		d.push_back(std::make_pair(std::max(std::atoi(av[i]), atoi(av[i + 1])), std::min(std::atoi(av[i]), atoi(av[i + 1]))));
		i += 2;
	}
	if (ac % 2 == 0)
		d.push_back(std::make_pair(std::atoi(av[i]), -1));
	for (std::deque< std::pair<int, int> >::iterator it = d.begin(); it != d.end(); ++it)
	{
		std::cout << (it)->first << " " << (it)->second << std::endl;
	}
}