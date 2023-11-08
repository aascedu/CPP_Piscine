#include "ICharacter.hpp"

ICharacter::ICharacter()
{
	std::cout << "ICharacter Default constructor call" << std::endl;
}

ICharacter::ICharacter( const ICharacter &ref )
{
	(*this) = ref;
	std::cout << "ICharacter Copy constructor call" << std::endl;
}

ICharacter::~ICharacter()
{
	std::cout << "ICharacter Destructor call" << std::endl;
}

ICharacter	&ICharacter::operator=( const ICharacter &ref )
{
	(void)ref;
	std::cout << "ICharacter Copy assignment call" << std::endl;
	return (*this);
}
