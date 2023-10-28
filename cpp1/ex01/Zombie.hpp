#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>

class Zombie
{
private:
	std::string	name;
public:
	Zombie( void );
	~Zombie();
	void	announce( void );
	void	setName( std::string input );
};

Zombie* zombieHorde( int N, std::string name );

#endif