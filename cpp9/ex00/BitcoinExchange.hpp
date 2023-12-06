#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map>
# include <stdexcept>
# include <sstream>

void	fillMap(std::map<std::string, float> &m);
float	checkLine(std::string line);
void	parsing(char *filename);

#endif