#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <stdlib.h>

Base	*generate(void)
{
	std::srand(time( NULL ));
	int	random = std::rand() % 3 + 1;

	A	*retA;
	B	*retB;
	C	*retC;

	switch (random)
	{
	case 1:
		retA = new A();
		return ((retA));
		break;
	case 2:
		retB = new B();
		return ((retB));
		break;
	case 3:
		retC = new C();
		return ((retC));
		break;
	default:
		break;
	}
	return (NULL);
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Type A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Type B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Type C" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "Type A" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}

	try
	{		
		(void)dynamic_cast<B &>(p);
		std::cout << "Type B" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}

	try
	{		
		(void)dynamic_cast<C &>(p);
		std::cout << "Type C" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}
}

int	main(void)
{
	Base	*rand = generate();
	identify(rand);
	identify(*rand);
	delete rand;
	return (0);
}