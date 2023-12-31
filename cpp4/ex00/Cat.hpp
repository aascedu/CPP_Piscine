#ifndef CAT_HPP
# define CAT_HPP

# include "header.h"

class Cat : public Animal
{
	public:
		Cat();
		Cat( const Cat &ref );
		~Cat();
		Cat		&operator=( const Cat &ref );
		void	makeSound( void ) const;
};

#endif