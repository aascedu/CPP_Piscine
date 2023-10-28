#include "Zombie.hpp"

int	main(void)
{
	Zombie	foo;
	Zombie	*horde = zombieHorde(3, "Putin");

	foo.announce();
	delete[] horde;
	foo.setName("Amin Dada");
	foo.announce();
}