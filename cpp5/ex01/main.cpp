#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Form QNF("49:3", 120, 30);
	try
	{
		Bureaucrat prez("Francois Hollande", 1);
		prez.signForm(QNF);
		std::cout << QNF;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}