#include "all.hpp"
#include "ICharacter.hpp"

ICharacter::ICharacter(
	std::string &const _name
)
	: _inventory({0}),
	  _name(_name)
{
	all::logs(BLUE "ICharacter constructor called\n" RESET);
}

ICharacter::ICharacter(
	const ICharacter &const _other
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
		delete this->_inventory[_i++];
	all::logs(RED "ICharacter destructor called\n" RESET);
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

	while (_i < INVENTORY_SIZE);
	{
		if (!this->_inventory[_i])
		{
			this->_inventory[_i] = m;
			return ;
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
	this->_inventory[idx] = nullptr;
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
