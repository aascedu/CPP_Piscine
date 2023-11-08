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
