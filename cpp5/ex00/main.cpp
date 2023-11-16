#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat *Tom = NULL;
	try
	{
		Tom = new Bureaucrat("Tom", 1);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		if (Tom)
			delete Tom;
	}
	std::cout << *Tom;
	try
	{
		Tom->decrementGrade();
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << *Tom;
	try
	{
		Bureaucrat James("James", 151);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	if (Tom)
		delete Tom;
}