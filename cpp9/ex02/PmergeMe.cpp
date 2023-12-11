#include "PmergeMe.hpp"

// *********************************************************************************** //
//
//
//									UTILS
//
//
// *********************************************************************************** //

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
	i = 0;
	std::cout << "Before : ";
	while (av[i]) {
		std::cout << av[i] << " ";
		i++;
	}
	std::cout << std::endl;
}

std::vector< int >	createJacob(int n)
{
	int	prev = 1;
	int	next = 1;
	int	i;
	std::vector< int >	v;

	v.push_back(1);
	while (next < n) {
		i = next;
		while (i > prev) {
			v.push_back(i);
			i--;
		}
		prev = next;
		next += 2 * i;
	}
	i = n;
	while (i > prev) {
		v.push_back(i);
		i--;
	}
	return (v);
}

long long	ft_get_time_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

// *********************************************************************************** //
//
//
//									DEQUE
//
//
// *********************************************************************************** //

void	dequeSplit(std::deque< std::pair<int, int> > &d, std::deque< std::pair<int, int> > &d1, std::deque< std::pair<int, int> > &d2)
{
	int	i = 0;
	int	size = d.size();

	for (std::deque< std::pair<int, int> >::iterator it = d.begin(); it != d.end() ; ++it)
	{
		if (i < size / 2)
			d1.push_back(*it);
		else
			d2.push_back(*it);
		i++;
	}
	
}

std::deque< std::pair<int, int> >	dequeRecursiveMerge(std::deque< std::pair<int, int> > &d)
{
	std::deque< std::pair<int, int> > d1;
	std::deque< std::pair<int, int> > d2;

	dequeSplit(d, d1, d2);
	if (!(d1.size() < 2 && d2.size() < 2)) {
		d1 = dequeRecursiveMerge(d1);
		d2 = dequeRecursiveMerge(d2);
	}
	std::deque< std::pair<int, int> > result;
	std::merge(d1.begin(), d1.end(), d2.begin(), d2.end(), std::back_inserter(result));
	return (result);
}

std::deque< int >	dequeInsert(std::deque< std::pair<int, int> > d)
{
	int	nbInserted = 0;
	std::deque< int >	res;
	std::vector< int > jacob = createJacob(d.size());	

	std::deque< std::pair<int, int> >::iterator it;
	for (it = d.begin(); it != d.end(); ++it) {
		if (it->first != -1) {
			res.push_back(it->first);
		}
	}
	for (size_t i = 0; i < jacob.size(); i++) {
		it = d.begin();
		std::advance(it, jacob[i] - 1);
		if (it->second != -1) {
			int left = 0;
			int right = jacob[i] + nbInserted;
			int	middle = (right + left) / 2;
			while (right - left > 1) {
				if (it->second > res[middle])
					left = middle;
				else
					right = middle;
				middle = (right + left) / 2;
			}
			std::deque< int >::iterator pos = res.begin();
			if (it->second > *pos) {
				std::advance(pos, middle + 1);
			}
			res.insert(pos, it->second);
			nbInserted++;
		}
	}
	return (res);
}

std::deque< int >	dequeSort(int ac, char **av)
{
	std::deque< std::pair<int, int> > d;
	std::deque< int > result;
	int i = 1;

	while (i < ac - 1) {
		d.push_back(std::make_pair(std::max(std::atoi(av[i]), atoi(av[i + 1])), std::min(std::atoi(av[i]), atoi(av[i + 1]))));
		i += 2;
	}
	if (ac % 2 == 0)
		d.push_back(std::make_pair(std::atoi(av[i]), -1));
	d = dequeRecursiveMerge(d);
	result = dequeInsert(d);
	return (result);
}

// *********************************************************************************** //
//
//
//									VECTOR
//
//
// *********************************************************************************** //

void	vectorSplit(std::vector< std::pair<int, int> > &d, std::vector< std::pair<int, int> > &d1, std::vector< std::pair<int, int> > &d2)
{
	int	i = 0;
	int	size = d.size();

	for (std::vector< std::pair<int, int> >::iterator it = d.begin(); it != d.end() ; ++it)
	{
		if (i < size / 2)
			d1.push_back(*it);
		else
			d2.push_back(*it);
		i++;
	}
	
}

std::vector< std::pair<int, int> >	vectorRecursiveMerge(std::vector< std::pair<int, int> > &d)
{
	std::vector< std::pair<int, int> > d1;
	std::vector< std::pair<int, int> > d2;

	vectorSplit(d, d1, d2);
	if (!(d1.size() < 2 && d2.size() < 2)) {
		d1 = vectorRecursiveMerge(d1);
		d2 = vectorRecursiveMerge(d2);
	}
	std::vector< std::pair<int, int> > result;
	std::merge(d1.begin(), d1.end(), d2.begin(), d2.end(), std::back_inserter(result));
	return (result);
}

std::vector< int >	vectorInsert(std::vector< std::pair<int, int> > d)
{
	int	nbInserted = 0;
	std::vector< int >	res;
	std::vector< int > jacob = createJacob(d.size());	

	std::vector< std::pair<int, int> >::iterator it;
	for (it = d.begin(); it != d.end(); ++it) {
		if (it->first != -1) {
			res.push_back(it->first);
		}
	}
	for (size_t i = 0; i < jacob.size(); i++) {
		it = d.begin();
		std::advance(it, jacob[i] - 1);
		if (it->second != -1) {
			int left = 0;
			int right = jacob[i] + nbInserted;
			int	middle = (right + left) / 2;
			while (right - left > 1) {
				if (it->second > res[middle])
					left = middle;
				else
					right = middle;
				middle = (right + left) / 2;
			}
			std::vector< int >::iterator pos = res.begin();
			if (it->second > *pos) {
				std::advance(pos, middle + 1);
			}
			res.insert(pos, it->second);
			nbInserted++;
		}
	}
	return (res);
}

std::vector< int >	vectorSort(int ac, char **av)
{
	std::vector< std::pair<int, int> > d;
	std::vector< int > result;
	int i = 1;

	while (i < ac - 1) {
		d.push_back(std::make_pair(std::max(std::atoi(av[i]), atoi(av[i + 1])), std::min(std::atoi(av[i]), atoi(av[i + 1]))));
		i += 2;
	}
	if (ac % 2 == 0)
		d.push_back(std::make_pair(std::atoi(av[i]), -1));
	d = vectorRecursiveMerge(d);
	result = vectorInsert(d);
	return (result);
}
