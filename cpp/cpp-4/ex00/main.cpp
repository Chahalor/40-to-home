#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"

#define TITLE(exo, x) do {out(YELLOW BOLD UNDERLINE exo "\033[24m: " x RESET "\n")} while (0);
#define PART(x)  do {out(CYAN x RESET "\n")} while (0);

int	main(void)
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
		meta->makeSound();

	}
	{
		PART("Animals")
		const Animal	*random = new Animal();
		const Animal	*cat = new Dog();
		const Animal	*dog = new Cat();

		out(random->getType() << "\n")
		out(cat->getType() << "\n")
		out(dog->getType() << "\n")

		random->makeSound();
		cat->makeSound();
		dog->makeSound();

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

	}
	return 0;
}
