#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5)
{
	this->_target = "empty";
	// std::cout << "PresidentialPardonForm Default constructor call" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	// std::cout << "PresidentialPardonForm Destructor call" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &ref ) : AForm("PresidentialPardonForm", 25, 5)
{
	// std::cout << "PresidentialPardonForm Copy constructor call" << std::endl;
	*this = ref;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=( const PresidentialPardonForm &ref )
{
	if (this != &ref)
		*this = ref;
	// std::cout << "PresidentialPardonForm Copy operator call" << std::endl;
	return (*this);
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : AForm("PresidentialPardonForm", 25, 5)
{
	this->_target = target;
	// std::cout << "PresidentialPardonForm Default constructor call" << std::endl;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getIsSigned() == false)
	{
		std::cout << this->getName() << " is not signed" << std::endl;
		return ;
	}
	else
	{
		if (executor.getGrade() > this->getExecGrade())
			throw Bureaucrat::GradeTooLowException();
		else
			std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	}
}