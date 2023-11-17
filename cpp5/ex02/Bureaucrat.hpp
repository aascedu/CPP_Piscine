#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

class AForm;

# include <iostream>
# include <string>
# include "AForm.hpp"

# define MAX_GRADE 1
# define MIN_GRADE 150

class Bureaucrat
{
	private:
			std::string	_name;
			int			_grade;
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const std::string name, const int grade);
		Bureaucrat( const Bureaucrat &ref );
		Bureaucrat 			&operator=( const Bureaucrat &ref );
		const std::string	&getName( void ) const;
		int					getGrade( void ) const;
		void				incrementGrade();
		void				decrementGrade();
		void				signForm( AForm &ref );
		void				executeForm( const AForm &form );
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &ostream, const Bureaucrat &ref);

#endif