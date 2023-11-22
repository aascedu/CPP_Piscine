#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template < typename T >
void	iter(const T array[], int len, void func(const T &))
{
	int	i = -1;
	while (++i < len)
		func(array[i]);
}

template<typename T>
void	printData(const T data)
{
	std::cout << data << std::endl;
}

#endif