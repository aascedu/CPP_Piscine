#include "Cure.hpp"

Cure::Cure()
{
	this->_type = "cure";
	std::cout << "Cure Default constructor call" << std::endl;
}

Cure::Cure( const Cure &ref )
{
	(*this) = ref;
	std::cout << "Cure Copy constructor call" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure Destructor call" << std::endl;
}

Cure &Cure::operator=( const Cure &ref )
{
	this->_type = ref._type;
	std::cout << "Cure Copy assignment call" << std::endl;
	return (*this);
}

AMateria	*Cure::clone( void ) const
{
	AMateria	*temp = new Cure();

	return (temp);
}

void	Cure::use( ICharacter &target )
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}