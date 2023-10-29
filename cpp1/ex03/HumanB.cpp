#include "HumanB.hpp"

HumanB::HumanB()
{
}

HumanB::HumanB( std::string name ) : name(name)
{
	weapon = NULL;
}

HumanB::~HumanB()
{
}

void	HumanB::attack(void)
{
	if (weapon)
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void	HumanB::setWeapon( Weapon &weapon )
{
	this->weapon = &weapon;
}
