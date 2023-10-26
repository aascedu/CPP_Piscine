#include <locale>
#include <iostream>

class Contact
{
private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNbr;
	std::string darkestSecret;

public:
	Contact();
	void	setFirstName(void);
	void	setLastName(void);
	void	setNickname(void);
	void	setPhoneNbr(void);
	void	setDarkestSecret(void);
	void	getContact(void);
	void	printContactInBook(int i);
	~Contact();
};
