#include "AMateria.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main(void)
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("mee");
	AMateria* tmp0;
	AMateria* tmp1;
	AMateria* tmp2;
	AMateria* tmp3;

	tmp0 = src->createMateria("ice");
	me->equip(tmp0);
	tmp1 = src->createMateria("cure");
	me->equip(tmp1);
	tmp2 = src->createMateria("cure");
	me->equip(tmp2);
	tmp3 = src->createMateria("cure");
	me->equip(tmp3);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	me->unequip(3);
	me->equip(tmp3);
	me->use(0, *bob);

	me->unequip(2);
	delete tmp2;
	
	delete bob;
	delete me;
	delete src;
	return 0;
}