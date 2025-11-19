#pragma once

#include "ICharacter.hpp"

class Character: public virtual ICharacter
{
	private:
		/* data */
	public:
		Character(/* args */);
		~Character();

		const std::string	&getName() const = 0;
		void				equip(AMateria* m) = 0;
		void				unequip(int idx) = 0;
		void				use(int idx, ICharacter& target) = 0;
};

Character::Character(/* args */)
{
}

Character::~Character()
{
}
