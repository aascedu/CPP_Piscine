#include "ClapTrap.hpp"

ClapTrap::ClapTrap( std::string name ) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Default constructor call" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor call" << std::endl;
}

void	attack(const std::string& target)
{

}

void	takeDamage(unsigned int amount)
{

}

void	beRepaired(unsigned int amount)
{

}
