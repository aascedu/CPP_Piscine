#include "Form.hpp"

Form::Form() : _name("empty"), _isSigned(false), _signGrade(0), _execGrade(0)
{
	std::cout << "Form Default constructor call" << std::endl;
}

Form::~Form()
{
	std::cout << "Form Destructor call" << std::endl;
}

Form::Form( const Form &ref ) : _name(ref.getName()), _isSigned(ref.getIsSigned()), _signGrade(ref.getSignGrade()), _execGrade(ref.getExecGrade())
{
	std::cout << "Form Copy Constructor call" << std::endl;
}

Form	&Form::operator=( const Form &ref )
{
	this->_name = ref.getName();
	this->_isSigned = ref.getIsSigned();
	std::cout << "Form Copy operator call" << std::endl;
	return (*this);
}

Form::Form(std::string name, const int signGrade, const int execGrade) : _name(name),
																	_isSigned(false),
															   _signGrade(signGrade),
															   _execGrade(execGrade)
{
	if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	std::cout << "Form Constructor call" << std::endl;
}

const std::string	&Form::getName( void ) const
{
	return (this->_name);
}

bool		Form::getIsSigned( void ) const
{
	return (this->_isSigned);
}

int			Form::getSignGrade( void ) const
{
	return (this->_signGrade);
}

int			Form::getExecGrade( void ) const
{
	return (this->_execGrade);
}

std::ostream	&operator<<(std::ostream &ostream, const Form &ref)
{
	ostream << ref.getName() << " is signed : ";
	if (ref.getIsSigned() == true)
		ostream << "YES.";
	else
		ostream << "NO.";
	ostream << ". Grade needed to sign : " << ref.getSignGrade() << " and to execute it : " << ref.getExecGrade() << std::endl;
	return (ostream);
}

const char* Form::GradeTooHighException::what() const throw() {
	return ("Form's grade is too high!");
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("Form's grade is too low!");
}

const char* Form::FormAlreadySignedException::what() const throw() {
	return ("Form's is already signed!");
}

void	Form::beSigned( const Bureaucrat &ref )
{
	if (this->getIsSigned() == true)
		throw Form::FormAlreadySignedException();
	if (ref.getGrade() > this->_signGrade)
		throw Form::GradeTooHighException();
	this->_isSigned = true;
}
