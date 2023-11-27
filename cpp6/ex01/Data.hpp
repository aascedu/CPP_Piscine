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

			static uintptr_t	serialize(Data* ptr);
			static Data* 		deserialize(uintptr_t raw);
};

#endif