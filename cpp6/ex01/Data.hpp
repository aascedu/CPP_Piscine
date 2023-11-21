#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>

class Data
{
		private:
			std::string	_name;
		public:
			Data();
			~Data();
			Data( const std::string name );
			Data( const Data &ref );
			Data	&operator=( const Data &ref );
};

#endif