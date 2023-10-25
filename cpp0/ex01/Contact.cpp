#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void	Contact::setFirstName(void)
{
	std::string	input;

	input = "";
		std::cout << "First Name : ";
	while (input.length() == 0)
	{
		std::getline(std::cin, input);
		firstName = input;
	}
}

void	Contact::setLastName(void)
{
	std::string	input;

	while (1)
	{
		std::cout << "Last Name : ";
		std::getline(std::cin, input);
		if (input.length() != 0)
		{
			lastName = input;
			break ;
		}
	}
}

void	Contact::setNickname(void)
{
	std::string	input;

	while (1)
	{
		std::cout << "Nickname : ";
		std::getline(std::cin, input);
		if (input.length() != 0)
		{
			nickname = input;
			break ;
		}
	}
}

void	Contact::setPhoneNbr(void)
{
	std::string	input;

	while (1)
	{
		std::cout << "Phone Number : ";
		std::getline(std::cin, input);
		if (input.length() != 0)
		{
			phoneNbr = input;
			break ;
		}
	}
}

void	Contact::setDarkestSecret(void)
{
	std::string	input;

	while (1)
	{
		std::cout << "Darkest Secret : ";
		std::getline(std::cin, input);
		if (input.length() != 0)
		{
			darkestSecret = input;
			break ;
		}
	}
}
