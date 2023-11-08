#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Default constructor call" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain Destructor call" << std::endl;
}

Brain::Brain( const Brain &ref )
{
	*this = ref;
	std::cout << "Brain Copy constructor call" << std::endl;
}

Brain	&Brain::operator=( const Brain &ref )
{
	int i = -1;

	while (++i < 100)
		this->ideas[i] = ref.ideas[i];
	std::cout << "Brain Copy operator call" << std::endl;
	return (*this);
}

void	Brain::setIdeasHey( void )
{
	int	i = -1;
	while (++i < 100)
		this->ideas[i] = "Hey";
}

void	Brain::setIdeasHo( void )
{
	int	i = -1;
	while (++i < 100)
		this->ideas[i] = "Ho";
}

void	Brain::showIdeas( void )
{
	// int	i = -1;
	// while (++i < 100)
		std::cout << this->ideas[0] << std::endl;
}
