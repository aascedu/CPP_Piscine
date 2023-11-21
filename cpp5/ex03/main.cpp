#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern	stagiaire;

	AForm	*formPardon = NULL;
	try
	{
		formPardon = stagiaire.makeForm("shrubbery creation", "home");
	}
	catch(const std::exception& e)
	{
		std::cerr << "\033[1;33m" << e.what() << "\033[0m" << '\n';
	}
	try
	{
		if (formPardon)
		{
			Bureaucrat fake("Francocis Hollande", 150);
			Bureaucrat prez("Francois Hollande", 1);
			prez.signForm(*formPardon);
			formPardon->execute(prez);
			formPardon->execute(prez);
			formPardon->execute(fake);
			formPardon->execute(prez);
			if ( formPardon )
				delete formPardon;
		}
	}
	catch(std::exception &e)
	{
		std::cerr << "\033[1;33m" << e.what() << "\033[0m" << '\n';
		if (formPardon)
			delete formPardon;
	}
}