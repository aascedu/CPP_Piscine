#ifndef BRAIN_HPP
# define BRAIN_HPP

#include "header.h"

class Brain
{
	private:
		std::string	ideas[100];
	public:
		Brain();
		~Brain();
		Brain( const Brain &ref );
		Brain	&operator=( const Brain &ref );
		void	setIdeasHey( void );
		void	setIdeasHo( void );
		void	showIdeas( void );
};





#endif