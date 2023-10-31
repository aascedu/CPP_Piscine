#include "Weapon.hpp"

Weapon::Weapon()
{
}

Weapon::Weapon( std::string type ) : type(type)
{
}

Weapon::~Weapon()
{
}

const std::string&	Weapon::getType(void)
{
	return (this->type);
}
void	Weapon::setType(std::string newType)
{
	this->type = newType;
}