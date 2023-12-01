#include "easyfind.hpp"
#include <iostream>
#include <vector>

int	main(void)
{
	{
		std::vector<int> a;

		a.push_back(4);
		a.push_back(9999);
		a.push_back(7);
		a.push_back(6);
		a.push_back(2);

		std::vector<int>::iterator res = test<std::vector<int>::iterator>(a, 7);

		std::cout << *res << std::endl;
	}
	{
		std::vector<int> a;

		a.push_back(4);
		a.push_back(9999);
		a.push_back(7);
		a.push_back(6);
		a.push_back(2);

		std::vector<int>::iterator res = test<std::vector<int>::iterator>(a, 1111111);

		std::cout << *res << std::endl;
	}
}