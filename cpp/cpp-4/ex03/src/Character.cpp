#include <cstring>

#include "Character.hpp"

Character::Character(
	const std::string &_name
)
	: ICharacter(_name)
{
	int	_i = 0;

	while (_i < INVENTORY_SIZE)
		this->_inventory[_i++] = NULL;

	all::logs(BLUE "Character constructor called" RESET);
}

Character::Character(
	const Character &_other
)
	: ICharacter(_other)
{
	int	_i = 0;

	while (_i < INVENTORY_SIZE)
	{
		this->_inventory[_i] = _other._inventory[_i];
		_i++;
	}
}

Character::~Character(void)
{
	int	_i = 0;

	while (_i < INVENTORY_SIZE)
		delete this->_inventory[_i++];
	all::logs(RED "Character destructor called" RESET);
}

const std::string &Character::getName(void) const
{
	return (this->_name);
}
void	Character::equip(
	AMateria *m
)
{
	int	_i = 0;

	while (_i < INVENTORY_SIZE)
	{
		if (!this->_inventory[_i])
		{
			this->_inventory[_i] = m;
			break ;
		}
		_i++;
	}
}

void	Character::unequip(
	int idx
)
{
	if (unlikely(idx < 0 || idx > INVENTORY_SIZE))
		return ;
	this->_inventory[idx] = NULL;
}

void	Character::use(
	int idx,
	ICharacter& target
)
{
	if (unlikely(idx < 0 || idx > INVENTORY_SIZE))
		return ;
	else if (likely(this->_inventory[idx]))
		this->_inventory[idx]->use(target);
}
