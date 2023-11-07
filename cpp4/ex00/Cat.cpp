#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat Default constructor call" << std::endl;
	this->_type = "Cat";
}

Cat::Cat( const Cat &ref )
{
	*this = ref;
	std::cout << "Cat Copy constructor call" << std::endl;
}

Cat	&Cat::operator=( const Cat &ref )
{
	this->_type = ref._type;
	std::cout << "Cat Copy assignment operator call" << std::endl;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat Destructor call" << std::endl;
}

void	Cat::makeSound( void ) const
{
	std::cout << "meow." << std::endl;
}