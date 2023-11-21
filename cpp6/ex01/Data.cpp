#include "Data.hpp"

Data::Data()
{
}

Data::~Data()
{
}

Data::Data( const std::string name ) : _name(name)
{
}

Data::Data( const Data &ref )
{
	*this = ref;
}

Data	&Data::operator=( const Data &ref )
{
	if (this != &ref)
		*this = ref;
	return (*this);
}