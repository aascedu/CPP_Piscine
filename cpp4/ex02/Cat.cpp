#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat Default constructor call" << std::endl;
	this->_type = "Cat";
	this->_cerveau = new Brain();
}

Cat::Cat( const Cat &ref )
{
	this->_type = ref._type;
	this->_cerveau = new Brain();
	*(this->_cerveau) = *(ref._cerveau);
	std::cout << "Cat Copy constructor call" << std::endl;
}

Cat	&Cat::operator=( const Cat &ref )
{
	this->_type = ref._type;
	delete this->_cerveau;
	this->_cerveau = new Brain();
	*(this->_cerveau) = *(ref._cerveau);
	std::cout << "Cat Copy assignment operator call" << std::endl;
	return (*this);
}

Cat::~Cat()
{
	delete this->_cerveau;
	std::cout << "Cat Destructor call" << std::endl;
}

void	Cat::makeSound( void ) const
{
	std::cout << "meow." << std::endl;
}

void	Cat::callHey(void)
{
	this->_cerveau->setIdeasHey();
}

void	Cat::callHo(void)
{
	this->_cerveau->setIdeasHo();
}

void	Cat::showIdeas(void)
{
	this->_cerveau->showIdeas();
}