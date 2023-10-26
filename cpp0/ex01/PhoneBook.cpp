#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::addContact(int index)
{
	std::cout << "Adding a new contact." << std::endl;
	contact[index].setFirstName();
	contact[index].setLastName();
	contact[index].setNickname();
	contact[index].setPhoneNbr();
	contact[index].setDarkestSecret();
}

void	printBook(Contact *contact)
{
	int	i;

	std::cout << "-----------|----------|----------|-----------" << std::endl;
	std::cout << "-     INDEX|FIRST NAME| LAST NAME|  NICKNAME-" << std::endl;
	std::cout << "-----------|----------|----------|-----------" << std::endl;
	i = -1;
	while (++i < 8)
	{
		contact[i].printContactInBook(i);
		std::cout << "-----------|----------|----------|-----------" << std::endl;
	}
}

void	PhoneBook::searchContact(void)
{
	int			index;
	std::string	input;

	printBook(contact);
	std::cout << std::endl;
	while (1)
	{
		if (std::cin.eof())
			return;
		std::cout << "Enter Contact Index : ";
		std::getline(std::cin, input);
		if (input.length() == 1 && isdigit(input[0]) && input[0] != '0' && input[0] != '9')
		{
			index = input[0] - 49;
			break;
		}
	}
	contact[index].getContact();
}
