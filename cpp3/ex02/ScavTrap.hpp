#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
	public:
		ScavTrap();
		ScavTrap( const std::string name );
		ScavTrap( const ScavTrap &ref );
		~ScavTrap();
		void	guardGate();
		void	attack(const std::string& target);
		ScavTrap	&operator=( const ScavTrap &ref );
};

#endif