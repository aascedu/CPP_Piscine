#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	_name = "empty";
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap Default constructor call" << std::endl;
}

FragTrap::FragTrap( const std::string name)
{
	_name = name;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap Default constructor call" << std::endl;
}

FragTrap::FragTrap( const FragTrap &ref)
{
	*this = ref;
	std::cout << "FragTrap Copy constructor call" << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &ref)
{
	this->_attackDamage = ref._attackDamage;
	this->_energyPoints = ref._energyPoints;
	this->_hitPoints = ref._hitPoints;
	this->_name = ref._name;
	std::cout << "FragTrap Copy assignment operator call" << std::endl;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor call" << std::endl;
}

void		FragTrap::highFivesGuys(void)
{
	std::cout << "High Five Bro" << std::endl;
}