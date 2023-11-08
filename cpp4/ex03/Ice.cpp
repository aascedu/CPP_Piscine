#include "Ice.hpp"

Ice::Ice()
{
	this->_type = "ice";
	std::cout << "Ice Default constructor call" << std::endl;
}

Ice::Ice( const Ice &ref )
{
	(*this) = ref;
	std::cout << "Ice Copy constructor call" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Ice Destructor call" << std::endl;
}

Ice &Ice::operator=( const Ice &ref )
{
	this->_type = ref._type;
	std::cout << "Ice Copy assignment call" << std::endl;
	return (*this);
}

AMateria	*Ice::clone( void ) const
{
	AMateria	*temp = new Ice();

	return (temp);
}

void	Ice::use( ICharacter &target )
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}