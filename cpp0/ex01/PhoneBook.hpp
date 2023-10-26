#include "Contact.hpp"

class PhoneBook
{
private:
	Contact contact[8];
public:
	PhoneBook();
	~PhoneBook();
	void	addContact(int index);
	void	searchContact(void);
};
