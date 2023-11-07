#ifndef DOG_HPP
# define DOG_HPP

# include "header.h"

class Dog : public Animal
{
	private:
		Brain	*cerveau;
	public:
		Dog();
		Dog( const Dog &ref );
		~Dog();
		Dog		&operator=( const Dog &ref );
		void	makeSound( void ) const;
};

#endif