#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	AForm *formPardon = new PresidentialPardonForm("Bandit");
	try
	{
		Bureaucrat fake("Francocis Hollande", 150);
		Bureaucrat prez("Francois Hollande", 1);
		prez.signForm(*formPardon);
		formPardon->execute(prez);
		formPardon->execute(prez);
		formPardon->execute(fake);
		formPardon->execute(prez);
	}
	catch(std::exception &e)
	{
		std::cerr << "\033[1;33m" << e.what() << "\033[0m" << '\n';
	}
	AForm *form1 = new ShrubberyCreationForm("Le salon de Xavier Niel");
	try
	{
		Bureaucrat fake("Francocis Hollande", 150);
		Bureaucrat prez("Francois Hollande", 1);
		prez.signForm(*form1);
		form1->execute(prez);
		form1->execute(prez);
		form1->execute(fake);
		form1->execute(prez);
	}
	catch(const std::exception& e)
	{
		std::cerr << "\033[1;33m" << e.what() << "\033[0m" << '\n';
	}
	AForm *form2 = new RobotomyRequestForm("Gazo");
	try
	{
		Bureaucrat fake("Francocis Hollande", 150);
		Bureaucrat prez("Francois Hollande", 1);
		prez.signForm(*form2);
		prez.signForm(*form2);
		form2->execute(prez);
		form2->execute(fake);
		form2->execute(prez);
	}
	catch(const std::exception& e)
	{
		std::cerr << "\033[1;33m" << e.what() << "\033[0m" << '\n';
	}
	AForm *form3 = new PresidentialPardonForm("Manu Max");
	Bureaucrat	last("Dark Vador", 1);
	last.executeForm(*form3);
	last.signForm(*form3);
	last.executeForm(*form3);
	delete formPardon;
	delete form1;
	delete form2;
	delete form3;
}