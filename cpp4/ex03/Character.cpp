#include "Character.hpp"

Character::Character() : _name("empty")
{
	int	i = -1;
	while (++i < 4)
		this->_spells[i] = NULL;
	std::cout << "Character Default constructor call" << std::endl;
}

Character::Character( const Character &ref )
{
	this->_name = ref._name;
	int	i = -1;
	while (++i < 4)
	{
		if (ref._spells[i])
			this->_spells[i] = ref._spells[i]->clone();
		else
			this->_spells[i] = NULL;
	}
	std::cout << "Character Copy constructor call" << std::endl;
}

Character::Character( const std::string name ) : _name(name)
{
	int	i = -1;
	while (++i < 4)
		this->_spells[i] = NULL;
	std::cout << "Character Input constructor call" << std::endl;
}

Character::~Character()
{
	int	i = -1;
	while (++i < 4)
	{
		if (this->_spells[i])
			delete this->_spells[i];
	}
	std::cout << "Character Destructor call" << std::endl;
}

Character	&Character::operator=( const Character &ref )
{
	this->_name = ref._name;
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
	std::cout << "Character Copy assignment call" << std::endl;
	return (*this);
}

std::string const &Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	if (m == NULL)
	{
		std::cout << "Not a known spell, the spell you asked to equip is NULL" << std::endl;
		return ;
	}
	int	i = -1;
	while (++i < 4)
	{
		if (this->_spells[i] == NULL)
		{
			this->_spells[i] = m;
			// delete m;
			std::cout << "Materia added to inventory spot nb : " << i + 1 << std::endl;
			return ;
		}
	}
	std::cout << "No empty spot in inventory" << std::endl;
}

void Character::unequip(int idx)
{
	this->_spells[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (this->_spells[idx] != NULL)
	{
		std::cout << this->getName() << " : ";
		this->_spells[idx]->use(target);
		delete this->_spells[idx];
		this->_spells[idx] = NULL;
	}
	else
		std::cout << "No Spell in the inventory spot nb : " << idx << std::endl;
}
