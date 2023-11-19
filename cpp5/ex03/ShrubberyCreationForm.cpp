#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
	this->_target = "empty";
	// std::cout << "ShrubberyCreationForm Default constructor call" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	// std::cout << "ShrubberyCreationForm Destructor call" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &ref ) : AForm("ShrubberyCreationForm", 145, 137)
{
	// std::cout << "ShrubberyCreationForm Copy constructor call" << std::endl;
	*this = ref;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=( const ShrubberyCreationForm &ref )
{
	if (this != &ref)
		*this = ref;
	// std::cout << "ShrubberyCreationForm Copy operator call" << std::endl;
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : AForm("ShrubberyCreationForm", 145, 137)
{
	this->_target = target;
	// std::cout << "ShrubberyCreationForm Default constructor call" << std::endl;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::ofstream	outfile;

	if (executor.getGrade() > this->getExecGrade())
		throw Bureaucrat::GradeTooLowException();
	if (this->getIsSigned() == true)
	{
		std::string	filename = this->_target;
		filename.insert(filename.length(), "_shrubbery");
		std::ofstream	outfile;
		outfile.open(filename.c_str());
		if (!outfile)
		{
			std::cout << "Error when creating " << this->_target << "_shrubbery" << std::endl;
			return ;
		}
		outfile << "      🖕🖕🖕,🖕🖕🖕🖕🖕🖕🖕\n       ,\'🖕🖕 \\\\-*🖕🖕🖕🖕🖕🖕🖕\n ;🖕🖕🖕🖕🖕*🖕   _🖕🖕🖕🖕\"\n  ,🖕🖕🖕       \\(_.*🖕🖕🖕🖕.\n  🖕 *🖕🖕, ,🖕🖕🖕🖕*(    \'\n🖕^     ,*🖕🖕🖕 )\\|,🖕🖕*🖕,_\n     *🖕    \\/ #).-\"*🖕🖕*\n         _.) ,/ *🖕,\n _________/)#(_________" << std::endl;
		outfile.close();

	}
	else
		throw AForm::FormNotSignedException();
}

const std::string	&ShrubberyCreationForm::getTarget( void ) const
{
	return (this->_target);
}