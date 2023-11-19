#include "AForm.hpp"

AForm::AForm() : _name("empty"), _isSigned(false), _signGrade(0), _execGrade(0)
{
	// std::cout << "AForm Default constructor call" << std::endl;
}

AForm::~AForm()
{
	// std::cout << "AForm Destructor call" << std::endl;
}

AForm::AForm( const AForm &ref ) : _name(ref.getName()), _isSigned(ref.getIsSigned()), _signGrade(ref.getSignGrade()), _execGrade(ref.getExecGrade())
{
	// std::cout << "AForm Copy Constructor call" << std::endl;
}

AForm	&AForm::operator=( const AForm &ref )
{
	this->_name = ref.getName();
	this->_isSigned = ref.getIsSigned();
	// std::cout << "AForm Copy operator call" << std::endl;
	return (*this);
}

AForm::AForm(std::string name, const int signGrade, const int execGrade) : _name(name),
																	_isSigned(false),
															   _signGrade(signGrade),
															   _execGrade(execGrade)
{
	if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooLowException();
	if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
	// std::cout << "AForm Constructor call" << std::endl;
}

const std::string	&AForm::getName( void ) const
{
	return (this->_name);
}

bool		AForm::getIsSigned( void ) const
{
	return (this->_isSigned);
}

int			AForm::getSignGrade( void ) const
{
	return (this->_signGrade);
}

int			AForm::getExecGrade( void ) const
{
	return (this->_execGrade);
}

std::ostream	&operator<<(std::ostream &ostream, const AForm &ref)
{
	ostream << ref.getName() << " is signed : ";
	if (ref.getIsSigned() == true)
		ostream << "YES.";
	else
		ostream << "NO.";
	ostream << ". Grade needed to sign : " << ref.getSignGrade() << " and to execute it : " << ref.getExecGrade() << std::endl;
	return (ostream);
}

const char* AForm::GradeTooHighException::what() const throw() {
	return ("AForm's grade is too high!");
}

const char* AForm::GradeTooLowException::what() const throw() {
	return ("AForm's grade is too low!");
}

const char* AForm::FormAlreadySignedException::what() const throw() {
	return ("Form's is already signed!");
}

const char* AForm::FormNotSignedException::what() const throw() {
	return ("Form's is not signed!");
}

void	AForm::beSigned( const Bureaucrat &ref )
{
	if (ref.getGrade() > this->_signGrade)
		throw Bureaucrat::GradeTooLowException();
	if (this->_isSigned == true)
		throw AForm::FormAlreadySignedException();
	this->_isSigned = true;
}
