#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ScavTrap.hpp"

class FragTrap : public ClapTrap
{
	private:
	public:
		FragTrap();
		FragTrap( const std::string name );
		FragTrap( const FragTrap &ref );
		~FragTrap();
		FragTrap	&operator=(const FragTrap &ref);
		void		highFivesGuys(void);
};

#endif