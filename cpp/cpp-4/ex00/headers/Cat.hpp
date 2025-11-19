#pragma once

#include "Animal.hpp"

class Cat: public virtual Animal
{
	private:
		;
	public:
		Cat(/* args */);
		~Cat();

		void		makeSound(void) const;
		std::string	getType(void) const;

		Cat			&operator=(const Cat &_other);
	};
