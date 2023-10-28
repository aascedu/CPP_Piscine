#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie( void )
{
	 name = "init";
}

Zombie::~Zombie()
{
	std::cout << this->name << " destructor called." << std::endl;
}

void	Zombie::announce( void )
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName( std::string input )
{
	this->name = input;
}