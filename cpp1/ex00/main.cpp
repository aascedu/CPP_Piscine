#include "Zombie.hpp"

int	main(void)
{
	Zombie	foo("HEEEE");
	Zombie	*hello = newZombie("hello");

	randomChump("Scope");
	hello->announce();
	foo.announce();
	delete hello;
}