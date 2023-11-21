#ifndef FORM_HPP
# define FORM_HPP

class Bureaucrat;

# include <iostream>
# include <Bureaucrat.hpp>

class Form
{
	private:
		const std::string 	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_execGrade;

	public:
		Form();
		~Form();
		Form( const Form &ref );
		Form	&operator=( const Form &ref );
		Form(std::string name, const int signGrade, const int execGrade);
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
		class FormAlreadySignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		const std::string	&getName( void ) const;
		bool				getIsSigned( void ) const;
		int					getSignGrade( void ) const;
		int					getExecGrade( void ) const;
		void				beSigned( const Bureaucrat &ref );
};

std::ostream	&operator<<(std::ostream &ostream, const Form &ref);

#endif