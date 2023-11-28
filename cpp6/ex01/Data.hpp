#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <stdint.h>

struct Data
{
	int	a;
};

class Serializer
{
		private:
			Serializer();
			~Serializer();
			Serializer( const Serializer &ref );
			Serializer	&operator=( const Serializer &ref );
		public:
			static uintptr_t	serialize(Data* ptr);
			static Data* 		deserialize(uintptr_t raw);
};

#endif