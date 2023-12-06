#include "RPN.hpp"

bool	fromCharset(char c, std::string charset)
{
	for (size_t i = 0; i < charset.length(); i++)
	{
		if (c == charset[i])
			return (true);
	}
	return (false);
}

void	parsing(char *input)
{
	std::string inputStr = input;
	int size = 0;

	for (size_t i = 0; i < inputStr.length(); i++) {
		if (!fromCharset(inputStr[i], "0123456789-+*/ "))
			throw std::invalid_argument("wrong char inside your input");
		if (inputStr[i] != ' ') {
			size++;
		}
		else if (inputStr[i] == ' ') {
			size = 0;
		}
		if (size > 1)
			throw std::invalid_argument("wrong format inside your input");
	}
	int	nbNbr = 0;
	int	nbSign = 0;
	for (size_t i = 0; i < inputStr.length(); i++)
	{
		if (isdigit(inputStr[i]))
			nbNbr++;
		else if (inputStr[i] == '+' || inputStr[i] == '-' || inputStr[i] == '*' || inputStr[i] == '/')
			nbSign++;
	}
	if (nbNbr != nbSign + 1 || nbSign == 0)
		throw std::invalid_argument("number of numbers and number of signs doesn't match");
}

void	fillStack(char *input)
{
	std::string str = input;
	std::stack<int> s;

	for (size_t i = 0; i < str.length(); i++)
	{
		if (isdigit(str[i]))
			s.push(str[i] - 48);
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
			if (s.size() >= 2) {
				int	nb2 = s.top();
				s.pop();
				int nb1 = s.top();
				s.pop();
				int result;
				if (str[i] == '+')
					result = nb1 + nb2;
				else if (str[i] == '-')
					result = nb1 - nb2;
				else if (str[i] == '*')
					result = nb1 * nb2;
				else if (str[i] == '/') {
					if (nb2 == 0)
						throw std::invalid_argument("dividing by 0... don't do that");
					result = nb1 / nb2;
				}
				s.push(result);
			}
		}
	}
	std::cout << s.top() << std::endl;
}