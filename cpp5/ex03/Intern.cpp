#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern( const Intern &ref )
{

}

Intern	&Intern::operator=( const Intern &ref )
{

}

AForm	*Intern::makeForm(std::string form, std::string target)
{
	PresidentialPardonForm	president(target);
	RobotomyRequestForm		robotomy(target);
	ShrubberyCreationForm	shrubbery(target);
	std::string	array[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	AForm		*array_constructor[3] = {&president, &robotomy, &shrubbery};

	int	i = -1;
	while (++i < 3)
	
}
