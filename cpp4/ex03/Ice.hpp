#ifndef ICE_HPP
# define ICE_HPP

#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice( const Ice &ref );
		~Ice();
		Ice			&operator=( const Ice &ref );
		AMateria*	clone( void ) const;
		void		use( ICharacter &target );
};

#endif