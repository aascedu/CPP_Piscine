#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*_spells[4];
	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource( const MateriaSource &ref );
		MateriaSource	&operator=( const MateriaSource &ref );
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};

#endif