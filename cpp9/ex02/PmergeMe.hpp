#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <sstream>
# include <stdexcept>
# include <stdlib.h>
# include <deque>
# include <vector>
# include <algorithm>
# include <sys/time.h>

void	verifyInput(char **av);
long long	ft_get_time_ms(void);

std::vector< int >	createJacob(int n);

std::deque< int >	dequeSort(int ac, char **av);
std::deque< int >	dequeInsert(std::deque< std::pair<int, int> > d);
std::deque< std::pair<int, int> >	dequeRecursiveMerge(std::deque< std::pair<int, int> > &d);
void	dequeSplit(std::deque< std::pair<int, int> > &d, std::deque< std::pair<int, int> > &d1, std::deque< std::pair<int, int> > &d2);

std::vector< int >	vectorSort(int ac, char **av);
std::vector< int >	vectorInsert(std::vector< std::pair<int, int> > d);
std::vector< std::pair<int, int> >	vectorRecursiveMerge(std::vector< std::pair<int, int> > &d);
void	vectorSplit(std::vector< std::pair<int, int> > &d, std::vector< std::pair<int, int> > &d1, std::vector< std::pair<int, int> > &d2);

#endif