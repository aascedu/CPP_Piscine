#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	thea("Thea");
	ClapTrap	henri("Henri");
	ClapTrap	test;

	test = thea;

	test.attack("Mao Zedong");

	thea.attack("Vladimir Putin");
	thea.beRepaired(0);
	thea.beRepaired(-1);
	thea.takeDamage(5);
	thea.attack("Amid Dada");
	thea.beRepaired(22);
	thea.beRepaired(22);
	thea.beRepaired(22);
	thea.beRepaired(0);
	thea.beRepaired(0);
	thea.beRepaired(0);
	thea.beRepaired(0);
	thea.beRepaired(0);
	thea.beRepaired(0);
	thea.beRepaired(1);
	thea.attack("Amid Dada");

	henri.beRepaired(200);
	henri.takeDamage(-100);
	henri.takeDamage(-1);
	
	return (0);
}