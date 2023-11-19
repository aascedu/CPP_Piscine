#ifndef ROBOTOMYREQUESTFORM_CPP
# define ROBOTOMYREQUESTFORM_CPP

# include "AForm.hpp"
# include <cstdlib>

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;
	public:
		RobotomyRequestForm();
		~RobotomyRequestForm();
		RobotomyRequestForm( const RobotomyRequestForm &ref );
		RobotomyRequestForm	&operator=( const RobotomyRequestForm &ref );
		RobotomyRequestForm( std::string target );
		void					execute(Bureaucrat const & executor) const;
		const std::string				&getTarget( void ) const;
};

#endif