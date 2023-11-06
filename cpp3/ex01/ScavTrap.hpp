#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
	public:
		ScavTrap();
		ScavTrap( const ScavTrap &ref );
		~ScavTrap();
		void	guardGate();
		ScavTrap	&operator=( const ScavTrap &ref );
};

#endif