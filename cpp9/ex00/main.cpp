#include "BitcoinExchange.hpp"

void	check_date(std::string line, int i)
{
		i = line.find('-', i);
		std::string year = line.substr(0, i);
		if (year.length() != 4)
			throw std::invalid_argument("wrong year format.");
		int	yearNbr;
		std::istringstream	ss_year(year);
		ss_year >> yearNbr;
		if (!ss_year.eof() || ss_year.fail())
			throw std::invalid_argument("year isn't an int.");
		if (yearNbr < 2009)
			throw std::invalid_argument("bitcoin was created after that date.");
		int	start = i + 1;
		i = line.find('-', start);
		std::string month = line.substr(start, i - start);
		if (month.length() != 2)
			throw std::invalid_argument("wrong month format.");
		int	monthNbr;
		std::istringstream	ss_month(month);
		ss_month >> monthNbr;
		if (!ss_month.eof() || ss_month.fail())
			throw std::invalid_argument("month isn't an int.");
		if (monthNbr < 1 || monthNbr > 12)
			throw std::invalid_argument("invalid month.");
		int	startDay = i + 1;
		i = line.find(' ', startDay);
		std::string day = line.substr(startDay, i - startDay);
		if (day.length() != 2)
			throw std::invalid_argument("wrong day format.");
		int	dayNbr;
		std::istringstream	ss_day(day);
		ss_day >> dayNbr;
		if (!ss_day.eof() || ss_day.fail())
			throw std::invalid_argument("day isn't an int.");
		if (dayNbr < 1 || dayNbr > 31)
			throw std::invalid_argument("invalid day.");
		if (yearNbr == 2009 && dayNbr < 3)
			throw std::invalid_argument("bitcoin was created after that date.");
		if (monthNbr == 2) {
			if (((!(yearNbr % 4) && yearNbr % 100) || !(yearNbr % 400)) && dayNbr > 29)
				throw std::invalid_argument("leap years only have 29 days in february.");
			else if (!((!(yearNbr % 4) && yearNbr % 100) || !(yearNbr % 400)) && dayNbr > 28)
				throw std::invalid_argument("non-leap years only have 28 days in february.");
		}
		std::cout << line << std::endl;
}

void	parsing(char *filename)
{
	std::ifstream	infile(filename);
	if (!infile.is_open()) {
		throw std::invalid_argument("file couldn't be opened.");
	}
	std::string line;
	std::getline(infile, line);
	if (line != "date | value") {
		throw std::invalid_argument("wrong format inside file.");
	}
	while (std::getline(infile, line)) {
		int	i = 0;
		try
		{
			check_date(line, i);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		//i = line.find('-', i);
		//std::string year = line.substr(0, i);
		//if (year.length() != 4)
		//	throw std::invalid_argument("wrong year format.");
		//int	check;
		//std::istringstream	ss(year);
		//ss >> check;
		//if (!ss.eof() || ss.fail())
		//	throw std::invalid_argument("year isn't an int.");
		//std::cout << year << std::endl;
	}
}

int	main(int ac, char **av)
{
	if (ac != 2) {
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}
	try
	{
		parsing(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}