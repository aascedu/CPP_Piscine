#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <limits.h>

class ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();
	public:
		ScalarConverter( const ScalarConverter &ref );
		ScalarConverter	&operator=( const ScalarConverter &ref );
		class ImpossibleException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class EmptyInputException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class WrongInputException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		static void convert(std::string &input);
};

bool	checkInput(std::string input);

#endif