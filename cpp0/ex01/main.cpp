#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	book;
	std::string	input;
	int			index;

	index = 0;

	while (1)
	{
		std::cout << "What do you want to do (ADD - SEARCH - EXIT) : ";
		std::cin >> input;
		if (input == std::EOF)
			return;
		if (input == "EXIT")
			break;
		else if (input == "ADD")
		{
			book.addContact(index);
			index++;
			if (index == 8)
				index = 0;
		}
	}
}