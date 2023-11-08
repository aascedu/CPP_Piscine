#ifndef CAT_HPP
# define CAT_HPP

class Brain;
# include "header.h"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain	*_cerveau;
	public:
		Cat();
		Cat( const Cat &ref );
		~Cat();
		Cat		&operator=( const Cat &ref );
		void	makeSound( void ) const;
		void	callHey(void);
		void	callHo(void);
		void	showIdeas(void);
};

#endif