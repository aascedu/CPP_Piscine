#include "ClapTrap.hpp"

ClapTrap::ClapTrap( std::string name ) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Default constructor call" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor call" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		this->_energyPoints--;
		std::cout << "ClapTrap " << this->_name << " attacks " << target << " causing " << this->_attackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->_name << " not enough energy points or hit points (EP:" << this->_energyPoints << "/HP:" << this->_hitPoints << ")" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints > 0)
	{
		if (this->_hitPoints - amount <= 0)
		{
			this->_hitPoints = 0;
			std::cout << "ClapTrap " << this->_name << " has died by taking " << amount << " points of damage!" << std::endl;
		}
		else
		{
			this->_hitPoints = this->_hitPoints - amount;
			std::cout << "ClapTrap " << this->_name << " took " << amount << " points of damage!" << std::endl;
		}
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		this->_energyPoints--;
		this->_hitPoints += amount;
		std::cout << "ClapTrap " << this->_name << " gained " << amount << " and now have " << this->_hitPoints << " points of health!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->_name << " not enough energy points or hit points (EP:" << this->_energyPoints << "/HP:" << this->_hitPoints << ")" << std::endl;
}
