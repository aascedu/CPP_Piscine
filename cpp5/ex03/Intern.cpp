#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
	// std::cout << "Intern Default constructor call" << std::endl;
}

Intern::~Intern()
{
	// std::cout << "Intern Destructor call" << std::endl;
}

Intern::Intern( const Intern &ref )
{
	*this = ref;
	// std::cout << "Intern Copy constructor call" << std::endl;
}

Intern	&Intern::operator=( const Intern &ref )
{
	// std::cout << "Intern Copy operator call" << std::endl;
	if (this != &ref)
		*this = ref;
	return (*this);
}

const char* Intern::NoFormException::what() const throw() {
	return ("No form found.");
}

AForm	*Intern::makeForm(std::string form, std::string target)
{
	AForm	*president = new PresidentialPardonForm(target);
	AForm	*robotomy = new RobotomyRequestForm(target);
	AForm	*shrubbery = new ShrubberyCreationForm(target);
	std::string	array[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	AForm		*array_constructor[3] = {president, robotomy, shrubbery};

	int	i = -1;
	while (++i < 3)
	{
		if (form == array[i])
		{
			for (int j = 0; j < 3; j++)
			{
				if (j != i)
					delete array_constructor[j];
			}
			std::cout << "Intern creates " << array_constructor[i]->getName() << std::endl;
			return (array_constructor[i]);
		}
	}
	delete array_constructor[0];
	delete array_constructor[1];
	delete array_constructor[2];
	throw Intern::NoFormException();
	return (NULL);
}
