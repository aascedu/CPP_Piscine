#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "header.h"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat( const WrongCat &ref );
		~WrongCat();
		WrongCat		&operator=( const WrongCat &ref );
		void	makeSound( void ) const;
};

#endif