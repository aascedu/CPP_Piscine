#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>

template< typename T >
T easyfind(T &arg, const int val)
{
	for (size_t i = 0; i < arg.size(); i++)
	{
		if (arg[i] == val)
			return (&arg[i]);
	}
	return (NULL);
}

#endif