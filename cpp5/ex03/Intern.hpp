#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"

class Intern
{
	public:
		Intern();
		~Intern();
		Intern( const Intern &ref );
		Intern	&operator=( const Intern &ref );
		AForm	*makeForm(std::string form, std::string target);
		class NoFormException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif