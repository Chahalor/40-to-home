#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public virtual Animal
{
	private:
		Brain	*_brain;

	public:
		Dog(/* args */);
		Dog(const Dog &_other);
		~Dog();

		void		makeSound(void) const;
		std::string	getType(void) const;
		void		addIdea(std::string &_idea);
		void		showIdea(void);

		Dog	&operator=(const Dog &_other);
};
