#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

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
		Bureaucrat &operator=( const Bureaucrat &ref );
		std::string	&getName( void );
		int	getGrade( void );
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

#endif