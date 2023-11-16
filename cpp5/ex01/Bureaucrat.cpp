#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("empty"), _grade(150)
{
	std::cout << "Bureaucrat Default constructor call" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Destructor call" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, const int grade)
{
	this->_name = name;
	if (grade < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
	std::cout << "Bureaucrat Name / Grade constructor call" << std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat &ref )
{
	this->_name = ref._name;
	this->_grade = ref._grade;
	std::cout << "Bureaucrat Copy constructor call" << std::endl;
}

Bureaucrat &Bureaucrat::operator=( const Bureaucrat &ref )
{
	this->_name = ref._name;
	this->_grade = ref._grade;
	std::cout << "Bureaucrat Copy operator call" << std::endl;
	return (*this);
}

const std::string	&Bureaucrat::getName( void ) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade( void ) const
{
	return (this->_grade);
}

void	Bureaucrat::incrementGrade()
{
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Bureaucrat's grade is too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Bureaucrat's grade is too low!");
}

std::ostream	&operator<<(std::ostream &ostream, const Bureaucrat &ref)
{
	ostream << ref.getName() << ", bureaucrat grade : " << ref.getGrade() << std::endl;
	return (ostream);
}

void	Bureaucrat::signForm( Form &ref )
{
	try
	{
		ref.beSigned(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << this->getName() << " couldn't sign " << ref.getName() << " because ";
		std::cerr << e.what() << '\n';
	}
	if (ref.getIsSigned() == true)
		std::cout << this->getName() << " signed " << ref.getName() << std::endl;
}
