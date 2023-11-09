#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	int	i = -1;
	while (++i < 4)
		this->_spells[i] = NULL;
	std::cout << "MateriaSource Default constructor call" << std::endl;
}

MateriaSource::~MateriaSource()
{
	int	i = -1;
	while (++i < 4)
	{
		if (this->_spells[i])
			delete this->_spells[i];
	}
	std::cout << "Character Destructor call" << std::endl;
}

MateriaSource::MateriaSource( const MateriaSource &ref )
{
	int	i = -1;
	while (++i < 4)
	{
		if (ref._spells[i])
			this->_spells[i] = ref._spells[i]->clone();
		else
			this->_spells[i] = NULL;
	}
	std::cout << "MateriaSource Copy constructor call" << std::endl;
}

MateriaSource	&MateriaSource::operator=( const MateriaSource &ref )
{
	int	i = -1;
	while (++i < 4)
	{
		if (this->_spells[i])
			delete this->_spells[i];
		if (ref._spells[i])
			this->_spells[i] = ref._spells[i]->clone();
		else
			this->_spells[i] = NULL;
	}
	std::cout << "MateriaSource Copy assignment call" << std::endl;
	return (*this);
}

void MateriaSource::learnMateria(AMateria *ref)
{
	int	i = -1;
	while (++i < 4)
	{
		if (this->_spells[i] == NULL)
		{
			this->_spells[i] = ref;
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	int	i = -1;
	while (++i < 4)
	{
		if (this->_spells[i] && this->_spells[i]->getType() == type)
			return (this->_spells[i]->clone());
	}
	return (NULL);
}
