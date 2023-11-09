#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string	_name;
		AMateria	*_spells[4];
	public:
		Character();
		Character( const Character &ref );
		Character( const std::string name );
		~Character();
		Character	&operator=( const Character &ref );
		std::string	const &getName() const;
		void		equip(AMateria* m);
		void		unequip(int idx);
		void		use(int idx, ICharacter& target);
};

#endif