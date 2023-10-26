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

void	Contact::getContact(void)
{
	std::cout << "First Name : " << firstName << std::endl;
	std::cout << "Last Name : " << lastName << std::endl;
	std::cout << "Nickname : " << nickname << std::endl;
	std::cout << "Phone Number : " << phoneNbr << std::endl;
	std::cout << "Darkest Secret : " << darkestSecret << std::endl;
}

void	Contact::printContactInBook(int i)
{
	std::cout << "-         " << i + 1 << "|";
	if (firstName.length() <= 10)
	{
		long unsigned int	i = -1;
		while (++i < 10 - firstName.length())
			std::cout << " ";
		std::cout << firstName;
	}
	else
	{
		for (unsigned i = 0; i < 10; i++)
		{
			if (i == 9)
				std::cout << ".";
			else if (i < firstName.length())
				std::cout << firstName.at(i);
		}
	}
	std::cout << "|";
	if (lastName.length() <= 10)
	{
		long unsigned int	i = -1;
		while (++i < 10 - lastName.length())
			std::cout << " ";
		std::cout << lastName;
	}
	else
	{
		for (unsigned i = 0; i < 10; i++)
		{
			if (i == 9)
				std::cout << ".";
			else if (i < lastName.length())
				std::cout << lastName.at(i);
		}
	}
	std::cout << "|";
	if (nickname.length() <= 10)
	{
		long unsigned int	i = -1;
		while (++i < 10 - nickname.length())
			std::cout << " ";
		std::cout << nickname;
	}
	else
	{
		for (unsigned i = 0; i < 10; i++)
		{
			if (i == 9)
				std::cout << ".";
			else if (i < nickname.length())
				std::cout << nickname.at(i);
		}
	}
	std::cout << "|";
	std::cout << std::endl;
}