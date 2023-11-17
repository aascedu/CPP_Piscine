#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
	this->_target = "empty";
	// std::cout << "RobotomyRequestForm Default constructor call" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	// std::cout << "RobotomyRequestForm Destructor call" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &ref ) : AForm("RobotomyRequestForm", 72, 45)
{
	// std::cout << "RobotomyRequestForm Copy constructor call" << std::endl;
	*this = ref;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=( const RobotomyRequestForm &ref )
{
	if (this != &ref)
		*this = ref;
	// std::cout << "RobotomyRequestForm Copy operator call" << std::endl;
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : AForm("RobotomyRequestForm", 72, 45)
{
	this->_target = target;
	// std::cout << "RobotomyRequestForm Default constructor call" << std::endl;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getIsSigned() == false)
		throw AForm::FormNotSignedException();
	else
	{
		if (executor.getGrade() > this->getExecGrade())
			throw Bureaucrat::GradeTooLowException();
		else
		{
			std::cout << "Les bonbonnes sont remplies de cocaïne (baw, flexin')\nDakatine en guise de protéine (wow, banks)\nTu connais, chez nous, que la 0.9 (hein)\nSi je sors le fer, c'est pas pour les meufs (hein)\nZéro bluff, je dégaine, pousse-toi, grr, paw\nJ'ai pas l'temps de ken mais tu peux me lehess\nAu pire des cas, j'me casse pendant que tu nehess (tu nehess)\nTe-ma la kichta (hey), te-ma la taille d'la kichta (hey)\nTe-ma la kichta (hey), te-ma la taille d'la kichta (hey)" << std::endl;
			std::srand(time( NULL ));
			int	nbr = rand() % 2;
			if (nbr == 0)
				std::cout << this->_target << " has been robotomized" << std::endl;
			else
				std::cout << this->_target << " has not been robotomized" << std::endl;
		}
	}
}