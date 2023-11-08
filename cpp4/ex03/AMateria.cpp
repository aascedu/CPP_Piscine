#include "AMateria.hpp"

AMateria::AMateria() : _type("undefined")
{
	std::cout << "AMateria Default constructor call" << std::endl;
}

AMateria::AMateria( const AMateria &ref )
{
	(*this) = ref;
	std::cout << "AMateria Copy constructor call" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "AMateria Destructor call" << std::endl;
}

AMateria	&AMateria::operator=( const AMateria &ref )
{
	this->_type = ref._type;
	std::cout << "AMateria Copy assignment call" << std::endl;
	return (*this);
}

AMateria::AMateria( std::string const &type )
{
	this->_type = type;
	std::cout << "AMateria Name constructor call" << std::endl;
}

std::string const &AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use( ICharacter &target)
{
	std::cout << "IDK THE MATERIA " << this->getType() << " on this guy : " << target.getName() << std::endl;
}