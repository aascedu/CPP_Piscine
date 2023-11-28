#include "Data.hpp"

Serializer::Serializer()
{
}

Serializer::~Serializer()
{
}

Serializer::Serializer( const Serializer &ref )
{
	*this = ref;
}

Serializer	&Serializer::operator=( const Serializer &ref )
{
	if (this != &ref)
		*this = ref;
	return (*this);
}