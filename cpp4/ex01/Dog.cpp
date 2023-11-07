#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog Default constructor call" << std::endl;
	this->_type = "Dog";
}

Dog::Dog( const Dog &ref )
{
	*this = ref;
	std::cout << "Dog Copy constructor call" << std::endl;
}

Dog	&Dog::operator=( const Dog &ref )
{
	this->_type = ref._type;
	std::cout << "Dog Copy assignment operator call" << std::endl;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog Destructor call" << std::endl;
}

void	Dog::makeSound( void ) const
{
	std::cout << "woof." << std::endl;
}