#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	_name = "empty";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap Default constructor call" << std::endl;
}

ScavTrap::ScavTrap( const std::string name ) : ClapTrap::ClapTrap( name )
{
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap Default constructor call" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap &ref )
{
	*this = ref;
	std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor call" << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &ref)
{
	this->_attackDamage = ref._attackDamage;
	this->_energyPoints = ref._energyPoints;
	this->_hitPoints = ref._hitPoints;
	this->_name = ref._name;
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
	return (*this);
}

void	ScavTrap::guardGate(void)
{
	std::cout << "Gate Keeper Mode! (Bombastic Side Eye)" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		this->_energyPoints--;
		std::cout << "ScavTrap " << this->_name << " attacks " << target << " causing " << this->_attackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ScavTrap " << this->_name << " not enough energy points or hit points (EP:" << this->_energyPoints << "/HP:" << this->_hitPoints << ")" << std::endl;
}