#include "all.hpp"
#include "ICharacter.hpp"

ICharacter::ICharacter(
	const std::string &_name
)
	: _name(_name)
{
	all::logs(BLUE "ICharacter constructor called" RESET);
}

ICharacter::ICharacter(
	const ICharacter &_other
)
	: _name(_other._name)
{
	int	_i = 0;

	while (_i < INVENTORY_SIZE)
	{
		this->_inventory[_i] = _other._inventory[_i];
		_i++;
	}
}

ICharacter::~ICharacter(void)
{
	int	_i = 0;

	while (_i < INVENTORY_SIZE)
	{
		if (this->_inventory[_i])
		{
			// delete this->_inventory[_i];
			this->_inventory[_i] = NULL;
		}
		_i++;
	}
	all::logs(RED "ICharacter destructor called" RESET);
}

const std::string &ICharacter::getName(void) const
{
	return (this->_name);
}
void	ICharacter::equip(
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

void	ICharacter::unequip(
	int idx
)
{
	if (unlikely(idx < 0 || idx > INVENTORY_SIZE))
		return ;
	this->_inventory[idx] = NULL;
}

void	ICharacter::use(
	int idx,
	ICharacter& target
)
{
	if (unlikely(idx < 0 || idx > INVENTORY_SIZE))
		return ;
	else if (likely(this->_inventory[idx]))
		this->_inventory[idx]->use(target);
}
