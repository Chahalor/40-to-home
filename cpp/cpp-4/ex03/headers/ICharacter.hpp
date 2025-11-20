#pragma once

#include <iostream>

#include "config.h"
#include "all.hpp"
#include "AMateria.hpp"

class AMateria;

class ICharacter
{
	protected:
		std::string	_name;
		AMateria	*_inventory[INVENTORY_SIZE];

	public:
		ICharacter(const std::string &_name);
		ICharacter(const ICharacter &_other);
		virtual ~ICharacter(void);

		virtual const std::string	&getName() const = 0;
		virtual void				equip(AMateria* m) = 0;
		virtual void				unequip(int idx) = 0;
		virtual void				use(int idx, ICharacter& target) = 0;

		ICharacter					&operator=(const ICharacter &_other);
};
