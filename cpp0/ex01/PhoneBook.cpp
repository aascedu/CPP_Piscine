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
