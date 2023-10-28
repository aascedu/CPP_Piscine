#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie( std::string instName ) : name(instName)
{
}

Zombie::~Zombie()
{
	std::cout << this->name << " destructor called." << std::endl;
}

void Zombie::announce( void )
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
