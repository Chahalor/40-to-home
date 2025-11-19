#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public virtual Animal
{
	private:
		Brain	*_brain;

	public:
		Cat(/* args */);
		Cat(const Cat &_other);
		~Cat();

		void		makeSound(void) const;
		std::string	getType(void) const;
		void		addIdea(std::string &_idea);
		void		showIdea(void);

		Cat	&operator=(const Cat &_other);
};

