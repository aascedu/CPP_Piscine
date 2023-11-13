#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog Default constructor call" << std::endl;
	this->_type = "Dog";
	this->_cerveau = new Brain();
}

Dog::Dog( const Dog &ref )
{
	this->_type = ref._type;
	this->_cerveau = new Brain();
	*(this->_cerveau) = *(ref._cerveau);
	std::cout << "Dog Copy constructor call" << std::endl;
}

Dog	&Dog::operator=( const Dog &ref )
{
	this->_type = ref._type;
	delete this->_cerveau;
	this->_cerveau = new Brain();
	*(this->_cerveau) = *(ref._cerveau);
	std::cout << "Dog Copy assignment operator call" << std::endl;
	return (*this);
}

Dog::~Dog()
{
	delete this->_cerveau;
	std::cout << "Dog Destructor call" << std::endl;
}

void	Dog::makeSound( void ) const
{
	std::cout << "woof." << std::endl;
}

void	Dog::callHey(void)
{
	this->_cerveau->setIdeasHey();
}

void	Dog::callHo(void)
{
	this->_cerveau->setIdeasHo();
}

void	Dog::showIdeas(void)
{
	this->_cerveau->showIdeas();
}
