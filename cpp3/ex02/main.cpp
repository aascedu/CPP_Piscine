#include "FragTrap.hpp"

int	main(void)
{
	FragTrap	frag("Albert");
	ScavTrap	scav("Boort");
	ClapTrap	clap("Cy");


	frag.highFivesGuys();
	frag.attack("Le pere Noel");
	frag.beRepaired(100);
	frag.takeDamage(5);
	return (0);
}