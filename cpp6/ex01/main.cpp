#include "Data.hpp"
#include <stdint.h>

uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

int	main(void)
{
	Data	*a = new Data;

	uintptr_t	raw = serialize(a);
	Data	*ptr = deserialize(raw);

	std::cout << a << std::endl;
	std::cout << ptr << std::endl;

	delete a;
}