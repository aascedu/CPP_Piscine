#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat Default constructor call" << std::endl;
	this->_type = "WrongCat";
}

WrongCat::WrongCat( const WrongCat &ref )
{
	*this = ref;
	std::cout << "WrongCat Copy constructor call" << std::endl;
}

WrongCat	&WrongCat::operator=( const WrongCat &ref )
{
	this->_type = ref._type;
	std::cout << "WrongCat Copy assignment operator call" << std::endl;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor call" << std::endl;
}

void	WrongCat::makeSound( void ) const
{
	std::cout << "wrong meow." << std::endl;
}