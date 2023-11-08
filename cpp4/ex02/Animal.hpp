#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	protected:
		std::string _type;
	public:
		Animal();
		Animal( const Animal &ref );
		virtual ~Animal();
		Animal				&operator=( const Animal &ref );
		std::string			getType( void ) const;
		virtual void		makeSound( void ) const = 0;
};

#endif