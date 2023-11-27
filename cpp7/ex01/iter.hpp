#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template < typename T, typename U, typename V >
void	iter(T array[], U len, V (func))
{
	if (!array || !func)
		return ;
	for (U i = 0; i < len; i++) {
		(func)(array[i]);
	}
}

#endif