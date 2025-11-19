#pragma once

#include "WrongAnimal.hpp"

class WrongDog: public virtual WrongAnimal
{
private:
	/* data */
public:
	WrongDog(/* args */);
	~WrongDog();

	void		makeSound(void) const;
	std::string	getType(void) const;
};
