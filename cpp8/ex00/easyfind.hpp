#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>

template<class InputIterator, class T>
InputIterator test(T &arg, const int val)
{
	return std::find(arg.begin(), arg.end(), val);
}

#endif