#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>

template< typename InputIterator >
InputIterator easyfind(InputIterator &first, const int val)
{
	return (find(first.begin(), first.end(), val));
}

#endif