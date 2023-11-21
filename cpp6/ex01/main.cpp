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
	Data	test("Arthur");
	uintptr_t	raw = serialize(&test);
	Data	*ptr = deserialize(raw);

	std::cout << &test << std::endl;
	std::cout << ptr << std::endl;
}