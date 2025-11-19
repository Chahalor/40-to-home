#include "Cat.hpp"

Cat::Cat(/* args */)
	: _brain(new Brain())
{
	this->_type = "Cat";
	outl(CYAN "Cat constructor called" RESET)
}

Cat::Cat(
	const Cat &_other
)
	: Animal(_other),
	 _brain(new Brain(*_other._brain))
{
	this->_type = "Cat";
	outl(CYAN "Cat constructor called" RESET)
}

Cat::~Cat()
{
	delete this->_brain;
	outl(hex(0xF57C00) << "Cat destructor called" << RESET)
}

void	Cat::makeSound(void) const
{
	out("Meow meow\n");
}

std::string	Cat::getType(void) const
{
	return (this->_type);
}

Cat	&Cat::operator=(
	const Cat &_other
)
{
	if (unlikely(this == &_other))
		return (*this);

	this->_type = _other._type;

	delete this->_brain;

	this->_brain = new Brain(*_other._brain);
	return (*this);
}

void	Cat::addIdea(
	std::string &_idea
)
{
	return (this->_brain->addIdea(_idea));
}

void	Cat::showIdea(void)
{
	int	_i = 0;

	while (_i < this->_brain->_nbIdea)
	{
		out("[" BLUE << _i << RESET "] " << this->_brain->_idea[_i] << "\n")
		_i++;
	}
}
