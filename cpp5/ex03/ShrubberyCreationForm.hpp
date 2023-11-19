#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;
	public:
		ShrubberyCreationForm();
		~ShrubberyCreationForm();
		ShrubberyCreationForm( const ShrubberyCreationForm &ref );
		ShrubberyCreationForm	&operator=( const ShrubberyCreationForm &ref );
		ShrubberyCreationForm( std::string target );
		void					execute(Bureaucrat const & executor) const;
		const std::string				&getTarget( void ) const;
};

#endif