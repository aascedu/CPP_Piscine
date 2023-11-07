#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
	protected:
		std::string _type;
	public:
		WrongAnimal();
		WrongAnimal( const WrongAnimal &ref );
		virtual ~WrongAnimal();
		WrongAnimal				&operator=( const WrongAnimal &ref );
		std::string			getType( void ) const;
		void		makeSound( void ) const;
};

#endif