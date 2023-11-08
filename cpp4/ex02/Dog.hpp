#ifndef DOG_HPP
# define DOG_HPP

class Brain;
# include "header.h"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain	*_cerveau;
	public:
		Dog();
		Dog( const Dog &ref );
		~Dog();
		Dog		&operator=( const Dog &ref );
		void	makeSound( void ) const;
		void	callHey(void);
		void	callHo(void);
		void	showIdeas(void);
};

#endif