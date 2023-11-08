#include "Animal.hpp"

Animal::Animal() : _type("unknown")
{
	std::cout << "Animal Default constructor call" << std::endl;
}

Animal::Animal( const Animal &ref )
{
	*this = ref;
	std::cout << "Animal Copy constructor call" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal Destructor call" << std::endl;
}

Animal  &Animal::operator=( const Animal &ref )
{
	this->_type = ref._type;
	std::cout << "Animal Copy assignment operator call" << std::endl;
	return (*this);
}

std::string	Animal::getType( void ) const
{
	return (this->_type);
}
