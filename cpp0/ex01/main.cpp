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
		std::getline(std::cin, input);
		if (input == "ADD")
		{
			book.addContact(index);
			index++;
			if (index == 8)
				index = 0;
		}
		else if (input == "EXIT")
			break;
		if (std::cin.eof())
		{
			std::cin.clear();
			std::cout << std::endl;
			break;
		}
	}
}