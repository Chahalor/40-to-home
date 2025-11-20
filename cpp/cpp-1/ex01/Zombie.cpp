#include "Zombie.hpp"

Zombie::Zombie(
	std::string _name
)
{
	this->_name = _name;
}

Zombie::Zombie(void)
{
	this->_name = "A random reanimated corpse";
}

Zombie::~Zombie()
{
	outl(RED << "Zombie " << this->_name << " hazbin destroyed" << RESET);
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(
	std::string &_name
)
{
	this->_name = _name;
}
