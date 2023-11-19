#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;
	public:
		PresidentialPardonForm();
		~PresidentialPardonForm();
		PresidentialPardonForm( const PresidentialPardonForm &ref );
		PresidentialPardonForm	&operator=( const PresidentialPardonForm &ref );
		PresidentialPardonForm( std::string target );
		void					execute(Bureaucrat const & executor) const;
		const std::string				&getTarget( void ) const;
};

#endif