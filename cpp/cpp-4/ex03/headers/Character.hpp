#pragma once

#include "ICharacter.hpp"

class Character: public virtual ICharacter
{
	private:
		/* data */
	public:
		Character(const std::string &_name);
		Character(const Character &_other);
		~Character();

		const std::string	&getName() const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);
};
