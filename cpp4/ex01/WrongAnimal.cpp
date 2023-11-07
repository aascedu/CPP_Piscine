#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("unknown")
{
	std::cout << "WrongAnimal Default constructor call" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal &ref )
{
	*this = ref;
	std::cout << "WrongAnimal Copy constructor call" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor call" << std::endl;
}

WrongAnimal  &WrongAnimal::operator=( const WrongAnimal &ref )
{
	this->_type = ref._type;
	std::cout << "WrongAnimal Copy assignment operator call" << std::endl;
	return (*this);
}

std::string	WrongAnimal::getType( void ) const
{
	return (this->_type);
}

void	WrongAnimal::makeSound( void ) const
{
	std::cout << "Bruits d'animal mauvais" << std::endl;
}