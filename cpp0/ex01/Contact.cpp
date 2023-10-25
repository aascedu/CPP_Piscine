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

	while (1)
	{
		if (std::cin.eof())
			return;
		std::cout << "First Name : ";
		std::getline(std::cin, input);
		if (input.length() != 0)
		{
			firstName = input;
			break;
		}
	}
}

void	Contact::setLastName(void)
{
	std::string	input;

	while (1)
	{
		if (std::cin.eof())
			return;
		std::cout << "Last Name : ";
		std::getline(std::cin, input);
		if (input.length() != 0)
		{
			lastName = input;
			break;
		}
	}
}

void	Contact::setNickname(void)
{
	std::string	input;

	while (1)
	{
		if (std::cin.eof())
			return;
		std::cout << "Nickname : ";
		std::getline(std::cin, input);
		if (input.length() != 0)
		{
			nickname = input;
			break;
		}
	}
}

void	Contact::setPhoneNbr(void)
{
	std::string	input;

	while (1)
	{
		if (std::cin.eof())
			return;
		std::cout << "Phone Number : ";
		std::getline(std::cin, input);
		if (input.length() != 0)
		{
			phoneNbr = input;
			break;
		}
	}
}

void	Contact::setDarkestSecret(void)
{
	std::string	input;

	while (1)
	{
		if (std::cin.eof())
			return;
		std::cout << "Darkest Secret : ";
		std::getline(std::cin, input);
		if (input.length() != 0)
		{
			darkestSecret = input;
			break;
		}
	}
}
