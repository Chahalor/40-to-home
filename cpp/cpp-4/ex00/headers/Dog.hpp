#pragma once

#include "Animal.hpp"

class Dog: public virtual Animal
{
	private:
		/* data */
	public:
		Dog(/* args */);
		~Dog();

		void		makeSound(void) const;
		std::string	getType(void) const;

		Dog			&operator=(const Dog &_other);
};
