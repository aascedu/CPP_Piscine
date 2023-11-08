#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

class AMateria;
# include "AMateria.hpp"

class ICharacter
{
	public:
		ICharacter();
		ICharacter( const ICharacter &ref );
		ICharacter	&operator=( const ICharacter &ref );
		virtual ~ICharacter();
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

#endif