#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

#define TITLE(exo, x) do {out(YELLOW BOLD UNDERLINE exo "\033[24m: " x RESET "\n")} while (0);
#define PART(x)  do {out(CYAN x RESET "\n")} while (0);

/*int	main(void)
{
	TITLE("Ex00", "Polymorphism")
	{
		PART("subject main")
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		j->makeSound();
		// meta->makeSound();

		delete meta;
		delete j;
		delete i;
	}
	{
		PART("Animals")
		// const Animal	*random = new Animal();
		const Animal	*cat = new Dog();
		const Animal	*dog = new Cat();

		// out(random->getType() << "\n")
		out(cat->getType() << "\n")
		out(dog->getType() << "\n")

		// random->makeSound();
		cat->makeSound();
		dog->makeSound();

		// delete random;
		delete cat;
		delete dog;
	}
	{
		PART("Wrongs Animals")

		const WrongAnimal	*random = new WrongAnimal();
		const WrongAnimal	*cat = new WrongCat();
		const WrongAnimal	*dog = new WrongDog();

		out(random->getType() << "\n")
		out(cat->getType() << "\n")
		out(dog->getType() << "\n")

		random->makeSound();
		cat->makeSound();
		dog->makeSound();

		delete random;
		delete cat;
		delete dog;
	}
	TITLE("Ex01", "Brain & Deep Copy")
	{
		PART("Copy")
		Cat			*old_cat = new Cat;
		std::string	_idea = "pissing the human";

		old_cat->addIdea(_idea);

		Cat	*yong_cat = new Cat(*old_cat);

		yong_cat->showIdea();

		delete old_cat;
		delete yong_cat;
	}
	{
		PART("The array of death")

		Animal	*_array[100] = {0};
		int		_i = 0;

		while (_i < 100)
		{
			if (std::rand() % 2)
				_array[_i] = new Cat;
			else
				_array[_i] = new Dog;
			_i++;
		}
		_i = 0;
		while (_i < 100)
		{
			out("[" BLUE << _i << RESET "] " << _array[_i]->getType() << "\n")
			_i++;
		}
		_i = 0;
		while (_i < 100)
			delete _array[_i++];
	}
	return 0;
}*/

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	return 0;
}
