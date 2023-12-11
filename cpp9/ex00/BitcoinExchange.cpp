#include "BitcoinExchange.hpp"



void	fillMap(std::map<std::string, float> &m)
{
	(void)m;
	std::ifstream	infile("data.csv");
	if (!infile.is_open()) {
		throw std::invalid_argument("database file couldn't be opened.");
	}
	std::string line;
	try
	{
		std::getline(infile, line);
		if (line != "date,exchange_rate") {
			throw std::invalid_argument("wrong format at begining of database file (\"date,exchange_rate\").");
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	while (std::getline(infile, line)) {
		std::string date;
		std::string valueString;
		float		value;

		date = line.substr(0, line.find(',', 0));
		valueString = line.substr(11, line.length() - 11);
		std::istringstream	ss(valueString);
		ss >> value;
		if (!ss.eof() || ss.fail())
			throw std::invalid_argument("value isn't a float.");
		m[date] = value;
	}
}

float	checkLine(std::string line)
{
	int i = 0;
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
	if (monthNbr == 4 || monthNbr == 6 || monthNbr == 9 || monthNbr == 11) {
		if (dayNbr > 30) {
			throw std::invalid_argument("only 30 days in this month.");
		}
	}
	else {
		if (dayNbr > 31) {
			throw std::invalid_argument("only 31 days in this month.");
		}
	}
	std::string pipe = line.substr(i, 3);
	if (pipe != " | ")
		throw std::invalid_argument("what did you put between date and value ? cmon...");
	std::string btcValue = line.substr(i + 3, line.length() - (i + 3));
	std::istringstream ss_btc(btcValue);
	float btc;
	ss_btc >> btc;
	if (!ss_btc.eof() || ss_btc.fail())
		throw std::invalid_argument("value isn't an int or float.");
	if (btc < 0 || btc > 1000)
		throw std::invalid_argument("value must be between 0 and 1000.");
	return (btc);
}

void	parsing(char *filename)
{
	std::map<std::string, float> m;
	try
	{
		fillMap(m);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::ifstream	infile(filename);
	if (!infile.is_open()) {
		throw std::invalid_argument("input file couldn't be opened.");
	}
	std::string line;
	try
	{
		std::getline(infile, line);
		if (line != "date | value") {
			throw std::invalid_argument("wrong format at begining of input file (\"date | value\").");
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	while (std::getline(infile, line)) {
		try
		{
			float value = checkLine(line);
				std::map<std::string, float>::iterator it;
			std::string date = line.substr(0, 10);
			it = m.upper_bound(date);
			if ( it != m.begin() )
				--it;
			std::cout << date << " => " << value << " = " << value * it->second << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}
