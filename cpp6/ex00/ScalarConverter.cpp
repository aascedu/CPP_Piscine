#include "ScalarConverter.hpp"
#include <string>

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter Default constructor call" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter Destructor call" << std::endl;
}

ScalarConverter::ScalarConverter( const ScalarConverter &ref )
{
	*this = ref;
	std::cout << "ScalarConverter Copy constructor call" << std::endl;
}

ScalarConverter	&ScalarConverter::operator=( const ScalarConverter &ref ) 
{
	std::cout << "ScalarConverter Copy operator call" << std::endl;
	if (this != &ref)
		*this = ref;
	return (*this);
}

const char* ScalarConverter::ImpossibleException::what() const throw() {
	return ("Impossible to convert.");
}

const char* ScalarConverter::EmptyInputException::what() const throw() {
	return ("Empty Input.");
}

const char* ScalarConverter::WrongInputException::what() const throw() {
	return ("Wrong Input.");
}

bool	isChar(std::string &input)
{
	if (input.length() == 1 && (isprint(input[0]) && !isdigit(input[0])))
		return (true);
	return (false);
}

bool	isInt(std::string &input)
{
	int	i = 0;
	while (input.c_str() && (input[i] == '-' || input[i] == '+'))
		i++;
	if (i > 1)
		return (false);
	while (input.c_str() && input[i])
	{
		if (!isdigit(input[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	isFloat(std::string &input)
{
	if (*(input.end() - 1) == 'f')
	{
		int i = 0;
		while (input.c_str() && (input[i] == '-' || input[i] == '+'))
			i++;
		if (i > 1 || !isdigit(input[i]))
			return (false);
		int dot = 0;
		while (input.c_str() && input[i])
		{
			if (input[i] == '.')
				dot++;
			i++;
		}
		if (dot != 1)
			return (false);
		i = input.find('.');
		if (input.c_str() && input[i - 1] && input[i + 1] && isdigit(input[i - 1]) && isdigit(input[i + 1]))
			return (true);
	}
	return (false);
}

bool	isDouble(std::string &input)
{
	int i = 0;
	while (input.c_str() && (input[i] == '-' || input[i] == '+'))
		i++;
	if (i > 1 || !isdigit(input[i]))
		return (false);
	int dot = 0;
	while (input.c_str() && input[i])
	{
		if (input[i] == '.')
			dot++;
		i++;
	}
	if (dot != 1)
		return (false);
	i = input.find('.');
	if (input.c_str() && input[i - 1] && input[i + 1] && isdigit(input[i - 1]) && isdigit(input[i + 1]))
		return (true);
	return (false);
}

bool	isPseudoDouble(std::string &input)
{
	std::string array[4] = {"-inf", "+inf", "inf", "nan"};

	for (int i = 0; i < 4; i++) {
		if (input == array[i])
			return (true);
	}
	return (false);
}

bool	isPseudoFloat(std::string &input)
{
	std::string array[4] = {"-inff", "+inff", "inff", "nanf"};

	for (int i = 0; i < 4; i++) {
		if (input == array[i])
			return (true);
	}
	return (false);
}

void ScalarConverter::convert(std::string &input)
{
	if (input.empty())
		throw ScalarConverter::EmptyInputException();
	else if (isPseudoFloat(input))
	{
		std::cout << "char : Non displayable." << std::endl;
		std::cout << "int : impossible." << std::endl;
		std::cout << "float : " << input << std::endl;
		input.erase(input.find_last_of('f'));
		std::cout << "double : " << input << std::endl;
	}
	else if (isPseudoDouble(input))
	{
		std::cout << "char : Non displayable." << std::endl;
		std::cout << "int : impossible." << std::endl;
		std::cout << "float : " << input << "f" << std::endl;
		std::cout << "double : " << input << std::endl;
	}
	else if (isChar(input)) {
		std::cout << "char : '" << input[0] << "'" << std::endl;
		std::cout << "int : " << static_cast<int>(input[0]) << "" << std::endl;
		std::cout << "float : " << static_cast<float>(input[0]) << "f" << std::endl;
		std::cout << "double : " << static_cast<double>(input[0]) << "" << std::endl;
	}
	else if (isInt(input)) {
		double	value = atof(input.c_str());
		if (value < 0 || value > 127)
			std::cout << "char : impossible." << std::endl;
		else if (!isprint(value))
			std::cout << "char : Non displayable." << std::endl;
		else
			std::cout << "char : '" << static_cast<char>(value) << "'" << std::endl;
		if (value > INT_MAX || value < INT_MIN)
			std::cout << "int : impossible." << std::endl;
		else
			std::cout << "int : " << value << "" << std::endl;
		std::cout << "float : " << static_cast<float>(value) << "f" << std::endl;
		std::cout << "double : " << static_cast<double>(value) << "" << std::endl;
	}
	else if (isFloat(input))
	{
		double	value = atof(input.c_str());
		if (value < 0 || value > 127)
			std::cout << "char : impossible." << std::endl;
		else if (!isprint(value))
			std::cout << "char : Non displayable." << std::endl;
		else
			std::cout << "char : '" << static_cast<char>(value) << "'" << std::endl;
		if (value > 2147483647.0f || value < INT_MIN)
			std::cout << "int : impossible." << std::endl;
		else
			std::cout << "int : " << static_cast<int>(value) << "" << std::endl;
		std::cout << "float : " << value << "f" << std::endl;
		std::cout << "double : " << static_cast<double>(value) << "" << std::endl;
	}
	else if (isDouble(input))
	{
		double	value = atof(input.c_str());
		if (value < 0 || value > 127)
			std::cout << "char : impossible." << std::endl;
		else if (!isprint(value))
			std::cout << "char : Non displayable." << std::endl;
		else
			std::cout << "char : '" << static_cast<char>(value) << "'" << std::endl;
		if (value > INT_MAX || value < INT_MIN)
			std::cout << "int : impossible." << std::endl;
		else
			std::cout << "int : " << static_cast<int>(value) << "" << std::endl;
		if (value > __FLT_MAX__ || value < __FLT_MIN__)
			std::cout << "float : impossible." << std::endl;
		else
			std::cout << "float : " << static_cast<float>(value) << "f" << std::endl;
		std::cout << "double : " << value << "" << std::endl;
	}
	else
		throw ScalarConverter::WrongInputException();
}
