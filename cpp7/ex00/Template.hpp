#ifndef TEMPLATE_HPP
# define TEMPLATE_HPP

template< typename T >
T const &	max(const T &x, const T &y) {
	return ( x > y ? x : y );
}

template< typename T >
T const &	min(const T &x, const T &y) {
	return ( x < y ? x : y );
}

template< typename T >
void	swap(T &x,  T &y) {
	T	temp;
	temp = x;
	x = y;
	y = temp;
}

#endif