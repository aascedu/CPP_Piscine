#ifndef AFORM_HPP
# define AFORM_HPP

class Bureaucrat;

# include <iostream>
# include <Bureaucrat.hpp>

class AForm
{
	private:
		const std::string 	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_execGrade;

	public:
		AForm();
		virtual ~AForm();
		AForm( const AForm &ref );
		AForm	&operator=( const AForm &ref );
		AForm(std::string name, const int signGrade, const int execGrade);
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
		class FormNotSignedException : public std::exception
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
		virtual void		execute(Bureaucrat const & executor) const = 0;
};

std::ostream	&operator<<(std::ostream &ostream, const AForm &ref);

#endif