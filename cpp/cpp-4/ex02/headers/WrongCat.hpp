#pragma once

#include "WrongAnimal.hpp"

class WrongCat: public virtual WrongAnimal
{
	private:
		/* data */
	public:
		WrongCat(/* args */);
		~WrongCat();

		void		makeSound(void) const;
		std::string	getType(void) const;

		virtual WrongCat	&operator=(const WrongCat &_other);
};
