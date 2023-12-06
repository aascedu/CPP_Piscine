#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stdexcept>
# include <stack>

void	parsing(char *input);
bool	fromCharset(char c, std::string charset);
void	fillStack(char *input);

#endif