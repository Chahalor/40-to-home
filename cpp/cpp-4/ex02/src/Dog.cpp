#include "Dog.hpp"

Dog::Dog(/* args */)
	: _brain(new Brain())
{
	this->_type = "Dog";
	outl(CYAN "Dog constructor called" RESET)
}

Dog::Dog(
	const Dog &_other
)
	: Animal(_other),
	 _brain(new Brain(*_other._brain))
{
	this->_type = "Dog";
	outl(CYAN "Dog constructor called" RESET)
}

Dog::~Dog()
{
	delete this->_brain;
	outl(hex(0xF57C00) << "Dog destructor called" << RESET)
}

void	Dog::makeSound(void) const
{
	out("Meow meow\n");
}

std::string	Dog::getType(void) const
{
	return (this->_type);
}

Dog	&Dog::operator=(
	const Dog &_other
)
{
	if (unlikely(this == &_other))
		return (*this);

	this->_type = _other._type;

	delete this->_brain;

	this->_brain = new Brain(*_other._brain);
	return (*this);
}

void	Dog::addIdea(
	std::string &_idea
)
{
	return (this->_brain->addIdea(_idea));
}

void	Dog::showIdea(void)
{
	int	_i = 0;

	while (_i < this->_brain->_nbIdea)
	{
		out("[" BLUE << _i << RESET "] " << this->_brain->_idea[_i] << "\n")
		_i++;
	}
}
