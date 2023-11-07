#include "header.h"

int main( void )
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete i;
	delete j;

	const WrongAnimal	*chatmauvais = new WrongCat();

	std::cout << chatmauvais->getType() << " " << std::endl;
	chatmauvais->makeSound();

	delete chatmauvais;
	return 0;
}