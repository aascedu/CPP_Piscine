#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Form QNF("49:3", 149, 9);
		Bureaucrat prez("Francois Hollande", 150);
		prez.incrementGrade( );
		prez.signForm(QNF);
		prez.signForm(QNF);
		std::cout << QNF;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}